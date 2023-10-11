static void
create_debug_console(void)
{
	AllocConsole();
	HWND ConsoleWindow = GetConsoleWindow();
	SetWindowPos(ConsoleWindow, HWND_TOP, 0, 0, 800, 600, SWP_SHOWWINDOW);
	HANDLE Console = CreateFileA("CON", GENERIC_WRITE, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0);
	SetStdHandle(STD_OUTPUT_HANDLE, Console);
}

static void
setup_raw_input(HWND Window)
{
	RAWINPUTDEVICE Mouse = {0};
	Mouse.usUsagePage = HID_USAGE_PAGE_GENERIC;
	Mouse.usUsage = HID_USAGE_GENERIC_MOUSE;
	Mouse.dwFlags = RIDEV_NOLEGACY;
	Mouse.hwndTarget = Window;
	RegisterRawInputDevices(&Mouse, 1, sizeof(Mouse));
}

static HMENU
create_main_menu(void)
{
	HMENU File = CreatePopupMenu();
	AppendMenuW(File, MF_STRING, MENUITEM_FILE_OPEN, L"Open...");
	HMENU Config = CreatePopupMenu();
	AppendMenuW(Config, MF_STRING, MENUITEM_CONFIG_VIDEO, L"Video");
	AppendMenuW(Config, MF_STRING, MENUITEM_CONFIG_AUDIO, L"Audio");
	AppendMenuW(Config, MF_STRING, MENUITEM_CONFIG_INPUT, L"Input");
	HMENU Misc = CreatePopupMenu();
	AppendMenuW(Misc, MF_STRING, MENUITEM_MISC_ABOUT, L"About");
	HMENU Result = CreateMenu();
	AppendMenuW(Result, MF_STRING | MF_POPUP, (UINT_PTR)File, L"File");
	AppendMenuW(Result, MF_STRING | MF_POPUP, (UINT_PTR)Config, L"Config");
	AppendMenuW(Result, MF_STRING | MF_POPUP, (UINT_PTR)Misc, L"Misc");
	return Result;
}

static HWND
create_basic_window(void)
{
	WNDCLASSEXW WindowClass = {0};
	WindowClass.cbSize = sizeof(WindowClass);
	WindowClass.lpfnWndProc = DefWindowProcW;
	WindowClass.lpszClassName = WNDCLASS_NAME;
	RegisterClassExW(&WindowClass);
	HMENU Menu = create_main_menu();
	HWND Result = CreateWindowExW(0, WNDCLASS_NAME, WINDOW_TITLE, WS_POPUP, 0, 0, 0, 0, 0, Menu, 0, 0);
	return Result;
}

static LRESULT CALLBACK
window_proc(HWND Window, UINT Message, WPARAM wParam, LPARAM lParam)
{
	LRESULT Result = 0;
	switch(Message)
	{
		case WM_SETCURSOR:
		{
			bool_t HideMouse = true;
			if(HideMouse)
			{
				if(LOWORD(lParam) == HTCLIENT)
				{
					SetCursor(0);
					Result = TRUE;
				}
			}
		} break;
		case WM_INPUT:
		{
			RAWINPUT Device;
			HRAWINPUT Mouse = (HRAWINPUT)lParam;
			UINT InputBufferSize = sizeof(Device);
			UINT BytesCopied = GetRawInputData(Mouse, RID_INPUT, &Device, &InputBufferSize, sizeof(Device.header));
			Assert(BytesCopied == InputBufferSize);
			float MouseSensitivity = 0.003f;
			Assert(Device.data.mouse.usFlags == MOUSE_MOVE_RELATIVE);
			LONG DeltaX = Device.data.mouse.lLastX;
			LONG DeltaY = Device.data.mouse.lLastY;
			camera* Camera = (camera*)GetWindowLongPtrW(Window, GWLP_USERDATA);
			Assert(Camera);
			Camera->Yaw -= DeltaX * MouseSensitivity;
			Camera->Pitch -= DeltaY * MouseSensitivity;
		} break;
		case WM_CLOSE:
		case WM_DESTROY:
		{
			PostQuitMessage(0);
		} break;
		default:
		{
			Result = DefWindowProcW(Window, Message, wParam, lParam);
		}
	}
	return Result;
}

static GLuint
CreateOpenGLShader(char* Source, GLenum Type)
{
	HANDLE File = CreateFileA(Source, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	Assert(File != INVALID_HANDLE_VALUE);
	DWORD FileSize = GetFileSize(File, 0);
	char* String = VirtualAlloc(0, FileSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	DWORD BytesRead = 0;
	ReadFile(File, String, FileSize, &BytesRead, 0);
	Assert(BytesRead == FileSize);
	GLuint Result = glCreateShader(Type);
	glShaderSource(Result, 1, &String, 0);
	glCompileShader(Result);
	GLint IsCompiled = 0;
	glGetShaderiv(Result, GL_COMPILE_STATUS, &IsCompiled);
	if(!IsCompiled)
	{
		GLint LogLength = 0;
		glGetShaderiv(Result, GL_INFO_LOG_LENGTH, &LogLength);
		char* ErrorLog = VirtualAlloc(0, LogLength, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
		glGetShaderInfoLog(Result, LogLength, 0, ErrorLog);
		MessageBoxA(0, ErrorLog, "Shader Error Log", MB_OK);
		VirtualFree(ErrorLog, 0, MEM_RELEASE);
	}
	VirtualFree(String, 0, MEM_RELEASE);
	return Result;
}

static GLuint
CreateOpenGLProgram(GLuint VertexShader, GLuint FragmentShader)
{
	GLuint Result = glCreateProgram();
	glAttachShader(Result, VertexShader);
	glAttachShader(Result, FragmentShader);
	glLinkProgram(Result);
	glDetachShader(Result, VertexShader);
	glDetachShader(Result, FragmentShader);
	glDeleteShader(VertexShader);
	glDeleteShader(FragmentShader);
	GLint IsLinked = 0;
	glGetProgramiv(Result, GL_LINK_STATUS, &IsLinked);
	if(!IsLinked)
	{
		GLint LogLength = 0;
		glGetProgramiv(Result, GL_INFO_LOG_LENGTH, &LogLength);
		char* ErrorLog = VirtualAlloc(0, LogLength, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
		glGetProgramInfoLog(Result, sizeof(ErrorLog), 0, ErrorLog);
		MessageBoxA(0, ErrorLog, "Shader Error Log", MB_OK);
		VirtualFree(ErrorLog, 0, MEM_RELEASE);
	}
	return Result;
}

float PLANE_2D_VERTS[] =
{
	-1, 0, -1,
	-1, 0,  1,
	 1, 0,  1,
	 1, 0,  1,
	 1, 0, -1,
	-1, 0, -1,
};

#if 0
void WinMainCRTStartup(void)
#else
int WINAPI
wWinMain(HINSTANCE Instance, HINSTANCE Unused, WCHAR* CmdLine, int CmdShow)
#endif
{
	HWND Existing = FindWindowW(WNDCLASS_NAME, WINDOW_TITLE);
	if(Existing)
	{
		WCHAR* Message = L"Flare is already running. Launch another instance?";
		UINT MessageType = MB_YESNO | MB_ICONINFORMATION;
		int Response = MessageBoxW(Existing, Message, WINDOW_TITLE, MessageType);
		if(Response == IDNO)
		{
			ExitProcess(0);
		}
	}

	PROGRAM_HINSTANCE = GetModuleHandleA(0);
	SYSTEM_DLL_USER32 = GetModuleHandleA("user32.dll");
	SYSTEM_DLL_KERNEL32 = GetModuleHandleA("kernel32.dll");
	//SYSTEM_IS_64BITS = system_is_64bit();
	QueryPerformanceFrequency(&PROCESSOR_FREQUENCY);

	GetModuleFileNameW(PROGRAM_HINSTANCE, FILENAME_EXE, ARRAYSIZE(FILENAME_EXE));
	memcpy(FILENAME_INI, FILENAME_EXE, sizeof(FILENAME_INI));
	memcpy(FILENAME_LOG, FILENAME_EXE, sizeof(FILENAME_LOG));
	PathCchRenameExtension(FILENAME_INI, sizeof(FILENAME_INI), L".ini");
	PathCchRenameExtension(FILENAME_LOG, sizeof(FILENAME_LOG), L".log");
	//HANDLE LogFile = CreateFileA(FILENAME_LOG, GENERIC_WRITE, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0);
	UINT SafeExit = GetPrivateProfileIntW(INI_SECTION_GENERAL, INI_KEY_GENERAL_SAFEEXIT, 0, FILENAME_INI);

	enable_process_dpi_awareness();

	HWND Window = create_basic_window();
	setup_raw_input(Window);
	HDC WindowDC = GetDC(Window);
	HGLRC ContextGL = create_opengl_context(WindowDC);
	Assert(glewInit() == GLEW_OK);

	SetWindowLongPtrW(Window, GWLP_WNDPROC, (LONG_PTR)window_proc);
	SetWindowPos(Window, 0, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	ShowWindow(Window, SW_MAXIMIZE);

	GLuint VertexShader = CreateOpenGLShader("../shaders/shader_vs.glsl", GL_VERTEX_SHADER);
	GLuint FragmentShader = CreateOpenGLShader("../shaders/shader_fs.glsl", GL_FRAGMENT_SHADER);
	GLuint ShaderProgram = CreateOpenGLProgram(VertexShader, FragmentShader);
	glUseProgram(ShaderProgram);

	GLuint VertexArray;
	GLuint VertexBuffer;
	glGenVertexArrays(1, &VertexArray);
	glGenBuffers(1, &VertexBuffer);

	RECT WindowRect;
	GetClientRect(Window, &WindowRect);
	LONG WindowWidth = WindowRect.right - WindowRect.left;
	LONG WindowHeight = WindowRect.bottom - WindowRect.top;
	glViewport(0, 0, WindowWidth, WindowHeight);

	glBindVertexArray(VertexArray);
	glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(PLANE_2D_VERTS), PLANE_2D_VERTS, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	glEnableVertexAttribArray(0);
	glClearColor(0.4f, 0.2f, 0.8f, 1.0f);

	camera Camera = {0};
	Camera.Position = (vector3){0, 1, 0};
	Camera.Right = VECTOR3_UNIT_X;
	Camera.Up = VECTOR3_UNIT_Y;
	Camera.Front = VECTOR3_UNIT_Z;
	SetWindowLongPtrW(Window, GWLP_USERDATA, (LONG_PTR)&Camera);
	float CameraSpeed = 5.0f;

	matrix4 Perspective = matrix4_perspective((float)M_PI/4, (float)WindowHeight/WindowWidth, 0.1f, 100);
	glUniformMatrix4fv(glGetUniformLocation(ShaderProgram, "Perspective"), 1, GL_FALSE, (float*)(&Perspective));

	LARGE_INTEGER T1, T2;
	QueryPerformanceFrequency(&T1);

	//HANDLE Threads[1];
	//Threads[0] = CreateThread(0, 0, thread_renderer, Window, 0, &THREAD_ID_RENDERER);

	MSG Message;
	for(;;)
	{
		while(PeekMessageW(&Message, 0, 0, 0, PM_REMOVE))
		{
			if(Message.message == WM_QUIT)
			{
				goto label_program_exit;
			}
			TranslateMessage(&Message);
			DispatchMessageW(&Message);
		}
		QueryPerformanceCounter(&T2);
		float DeltaTime = (float)(T2.QuadPart - T1.QuadPart)/PROCESSOR_FREQUENCY.QuadPart;
		T1 = T2;

		float MoveStep = CameraSpeed * DeltaTime;
		if(GetAsyncKeyState('W') >> 15)
		{
			vector3 Backward = Camera_AxisZ(Camera);
			vector3 Step = vector3_mul(Backward, -MoveStep);
			Camera.Position.X += Step.X;
			Camera.Position.Z += Step.Z;
		}
		if(GetAsyncKeyState('S') >> 15)
		{
			vector3 Backward = Camera_AxisZ(Camera);
			vector3 Step = vector3_mul(Backward, MoveStep);
			Camera.Position.X += Step.X;
			Camera.Position.Z += Step.Z;
		}
		if(GetAsyncKeyState('A') >> 15)
		{
			vector3 Left = Camera_AxisX(Camera);
			vector3 Step = vector3_mul(Left, -MoveStep);
			Camera.Position = vector3_add(Camera.Position, Step);
		}
		if(GetAsyncKeyState('D') >> 15)
		{
			vector3 Left = Camera_AxisX(Camera);
			vector3 Step = vector3_mul(Left, MoveStep);
			Camera.Position = vector3_add(Camera.Position, Step);
		}

		matrix4 View = CameraView(&Camera);
		glUniformMatrix4fv(glGetUniformLocation(ShaderProgram, "View"), 1, GL_FALSE, (float*)(&View));

		glClear(GL_COLOR_BUFFER_BIT);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		SwapBuffers(WindowDC);
	}
	WritePrivateProfileStringW(INI_SECTION_GENERAL, INI_KEY_GENERAL_SAFEEXIT, L"1", FILENAME_INI);
	WritePrivateProfileStringW(INI_SECTION_GRAPHICS, INI_KEY_GRAPHICS_API, L"1", FILENAME_INI);
label_program_exit:
	ExitProcess(0);
}
