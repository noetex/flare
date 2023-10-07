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

static LRESULT CALLBACK
window_proc(HWND Window, UINT Message, WPARAM wParam, LPARAM lParam)
{
	LRESULT Result = 0;
	switch(Message)
	{
		case WM_SETCURSOR:
		{
			bool_t HideMouse = false;
			if(HideMouse)
			{
				if(LOWORD(lParam) == HTCLIENT)
				{
					SetCursor(0);
					Result = TRUE;
				}
			}
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

float TRIANGLE_VERTS[] =
{
	-0.5, -0.5, 0.0,
	0.0, 0.5, 0.0,
	0.5, -0.5, 0.0,
};


void WinMainCRTStartup(void)
{
	SYSTEM_DLL_KERNEL32 = load_system_dll("kernel32.dll");
	SYSTEM_DLL_USER32 = load_system_dll("user32.dll");
	PROGRAM_HINSTANCE = GetModuleHandleA(0);
	bool_t A = system_is_64bit();
	enable_process_dpi_awareness();

	HWND Window = FindWindowW(WNDCLASS_NAME, WINDOW_TITLE);
	if(Window)
	{
		WCHAR* Message = L"Flare is already running. Launch another instance?";
		UINT MessageType = MB_YESNO | MB_ICONINFORMATION;
		int Response = MessageBoxW(Window, Message, WINDOW_TITLE, MessageType);
		if(Response == IDNO)
		{
			goto label_program_exit;
		}
	}

	AllocConsole();
	HANDLE Console = CreateFileA("CON", GENERIC_WRITE, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0);
	SetStdHandle(STD_OUTPUT_HANDLE, Console);
	char B[] = "Hello World";
	Assert(WriteFile(Console, B, sizeof(B), 0, 0));

	GetModuleFileNameW(PROGRAM_HINSTANCE, FILENAME_EXE, ARRAYSIZE(FILENAME_EXE));
	memcpy(FILENAME_INI, FILENAME_EXE, sizeof(FILENAME_INI));
	memcpy(FILENAME_LOG, FILENAME_EXE, sizeof(FILENAME_LOG));
	PathRenameExtensionW(FILENAME_INI, L".ini");
	PathRenameExtensionW(FILENAME_LOG, L".log");
	//HANDLE LogFile = CreateFileA(FILENAME_LOG, GENERIC_WRITE, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0);
	UINT SafeExit = GetPrivateProfileIntW(INI_SECTION_GENERAL, INI_KEY_GENERAL_SAFEEXIT, 0, FILENAME_INI);

	WNDCLASSEXW WindowClass = {0};
	WindowClass.cbSize = sizeof(WindowClass);
	WindowClass.lpfnWndProc = window_proc;
	WindowClass.lpszClassName = WNDCLASS_NAME;
	RegisterClassExW(&WindowClass);
	HMENU MainMenu = create_main_menu();
	Window = CreateWindowExW(0, WNDCLASS_NAME, WINDOW_TITLE, WS_POPUP, 0, 0, 0, 0, 0, MainMenu, 0, 0);
	//CreateThread(0, 0, thread_renderer, Window, 0, &THREAD_ID_RENDERER);

	HDC WindowDC = GetDC(Window);
	HGLRC ContextGL = create_opengl_context(WindowDC);
	Assert(glewInit() == GLEW_OK);
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
	glBufferData(GL_ARRAY_BUFFER, sizeof(TRIANGLE_VERTS), TRIANGLE_VERTS, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	glEnableVertexAttribArray(0);
	glClearColor(0.4f, 0.2f, 0.8f, 1.0f);

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
		glClear(GL_COLOR_BUFFER_BIT);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		GLenum Error = glGetError();
		Assert(SwapBuffers(WindowDC));
	}
	WritePrivateProfileStringW(INI_SECTION_GENERAL, INI_KEY_GENERAL_SAFEEXIT, L"1", FILENAME_INI);
	WritePrivateProfileStringW(INI_SECTION_GRAPHICS, INI_KEY_GRAPHICS_API, L"1", FILENAME_INI);
label_program_exit:
	ExitProcess(0);
}
