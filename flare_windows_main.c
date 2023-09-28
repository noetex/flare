static LRESULT CALLBACK
window_proc(HWND Window, UINT Message, WPARAM wParam, LPARAM lParam)
{
	LRESULT Result = 0;
	switch(Message)
	{
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

static HWND
create_main_window(void)
{
	WNDCLASSEXW WindowClass = {0};
	WindowClass.cbSize = sizeof(WindowClass);
	WindowClass.lpfnWndProc = window_proc;
	WindowClass.lpszClassName = WNDCLASS_NAME;
	WindowClass.style = CS_HREDRAW | CS_VREDRAW;
	WindowClass.hInstance = PROGRAM_HINSTANCE;
	RegisterClassExW(&WindowClass);
	HWND Result = CreateWindowExW(0, WNDCLASS_NAME, WINDOW_TITLE, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	return Result;
}

static HGLRC
create_opengl_context(HDC WindowDC)
{
	PIXELFORMATDESCRIPTOR Descriptor = {0};
	Descriptor.nSize = sizeof(Descriptor);
	Descriptor.nVersion = 1;
	Descriptor.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	Descriptor.iPixelType = PFD_TYPE_RGBA;
	Descriptor.cColorBits = 32;
	Descriptor.cDepthBits = 32;
	int PixelFormat = ChoosePixelFormat(WindowDC, &Descriptor);
	SetPixelFormat(WindowDC, PixelFormat, &Descriptor);
	DescribePixelFormat(WindowDC, PixelFormat, sizeof(Descriptor), &Descriptor);
	HGLRC Result = wglCreateContext(WindowDC);
	wglMakeCurrent(WindowDC, Result);
	return Result;
}

void WinMainCRTStartup(void)
{
	rpvgi__enable_process_dpi_awareness();
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
	Window = create_main_window();
	HDC WindowDC = GetDC(Window);
	HGLRC ContextGL = create_opengl_context(WindowDC);
	Assert(glewInit() == GLEW_OK);

	for(;;)
	{
		MSG Message;
		GetMessageW(&Message, 0, 0 , 0);
		if(Message.message == WM_QUIT)
		{
			break;
		}
		TranslateMessage(&Message);
		DispatchMessageW(&Message);
	}
label_program_exit:
	ExitProcess(0);
}
