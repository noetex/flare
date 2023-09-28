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
			//PostThreadMessageW(THREAD_ID_RENDERER, Message, 0, 0);
		} break;
#if 0
		case WM_GETMINMAXINFO:
		{
			MINMAXINFO* MinMaxInfo = (MINMAXINFO*)lParam;
			typedef struct tagMINMAXINFO {
			  POINT ptReserved;
			  POINT ptMaxSize;
			  POINT ptMaxPosition;
			  POINT ptMinTrackSize;
			  POINT ptMaxTrackSize;
			} MINMAXINFO, *PMINMAXINFO, *LPMINMAXINFO;
		} break;
#endif
		default:
		{
			Result = DefWindowProcW(Window, Message, wParam, lParam);
		}
	}
	return Result;
}

#if 0
static HMENU
create_window_menu(void)
{
	HMENU File = CreatePopupMenu();
	AppendMenuW(File, MF_STRING, MENUITEM_FILE_OPEN, L"Open");
	HMENU Config = CreatePopupMenu();
	AppendMenuW(Config, MF_STRING, MENUITEM_CONFIG_VIDEO, L"Video");
	AppendMenuW(Config, MF_STRING, MENUITEM_CONFIG_AUDIO, L"Audio");
	AppendMenuW(Config, MF_STRING, MENUITEM_CONFIG_INPUT, L"Input");
	HMENU Misc = CreatePopupMenu();
	AppendMenuW(Misc, MF_STRING, MENUITEM_MISC_ABOUT, L"About");
	HMENU Result = CreateMenu();
	AppendMenuW(File, MF_STRING | MF_POPUP, (UINT_PTR)File, L"File");
	AppendMenuW(File, MF_STRING | MF_POPUP, (UINT_PTR)Config, L"Config");
	AppendMenuW(File, MF_STRING | MF_POPUP, (UINT_PTR)Misc, L"Misc");
	return Result;
}
#endif

static HWND
create_main_window(void)
{
	HINSTANCE Instance = GetModuleHandleW(0);
	WNDCLASSEXW WindowClass =
	{
		.cbSize = sizeof(WindowClass),
		.lpfnWndProc = window_proc,
		.lpszClassName = L"flare_wndclass",
		.style = CS_HREDRAW | CS_VREDRAW,
		.hInstance = Instance,
		.hCursor = LoadCursorW(0, MAKEINTRESOURCEW(IDC_ARROW)),
		.hIcon = LoadIconW(0, MAKEINTRESOURCEW(IDI_APPLICATION)),
		.hIconSm = LoadIconW(0, MAKEINTRESOURCEW(IDI_APPLICATION)),
		.hbrBackground = (HBRUSH)(COLOR_BACKGROUND + 1),
		//.cbClsExtra = 0,
		//.cbWndExtra = 0,
		//.lpszMenuName = 0,
	};
	int ScreenWidth = GetSystemMetrics(SM_CXSCREEN);
	int ScreenHeight = GetSystemMetrics(SM_CYSCREEN);
	RegisterClassExW(&WindowClass);
	DWORD WindowStyle = WS_BORDER | WS_CLIPCHILDREN | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU;
	DWORD WindowStyleEx = WS_EX_ACCEPTFILES;
	HWND Result = CreateWindowExW(WindowStyleEx, FLARE_WNDCLASS_NAME, FLARE_WINDOW_TITLE, WindowStyle, 0, 0, ScreenWidth, ScreenHeight, 0, 0, 0, 0);
	Assert(Result);
	int ViewportWidth = ScreenWidth/2 - WINDOW_TOOLBAR_WIDTH - (2 * VIEWPORT_MARGIN_X);
	int ViewportHeight = ScreenHeight/2 - (3 * VIEWPORT_MARGIN_Y);
	int Viewport1X = WINDOW_TOOLBAR_WIDTH + VIEWPORT_MARGIN_X;
	int Viewport1Y = VIEWPORT_MARGIN_Y;
	int Viewport2X = Viewport1X + ViewportWidth + VIEWPORT_MARGIN_X;
	int Viewport2Y = Viewport1Y;
	int Viewport3X = Viewport1X;
	int Viewport3Y = Viewport1Y + ViewportHeight + VIEWPORT_MARGIN_Y;
	int Viewport4X = Viewport2X;
	int Viewport4Y = Viewport2Y + ViewportHeight + VIEWPORT_MARGIN_Y;
	DWORD ViewportStyle = WS_CHILD | WS_BORDER | WS_VISIBLE;
	DWORD ViewportStyleEx = WS_EX_OVERLAPPEDWINDOW | WS_EX_DLGMODALFRAME;
	Assert(CreateWindowExW(ViewportStyleEx, L"Static", 0, ViewportStyle, Viewport1X, Viewport1Y, ViewportWidth, ViewportHeight, Result, 0, 0, 0));
	Assert(CreateWindowExW(ViewportStyleEx, L"Static", 0, ViewportStyle, Viewport2X, Viewport2Y, ViewportWidth, ViewportHeight, Result, 0, 0, 0));
	Assert(CreateWindowExW(ViewportStyleEx, L"Static", 0, ViewportStyle, Viewport3X, Viewport3Y, ViewportWidth, ViewportHeight, Result, 0, 0, 0));
	Assert(CreateWindowExW(ViewportStyleEx, L"Static", 0, ViewportStyle, Viewport4X, Viewport4Y, ViewportWidth, ViewportHeight, Result, 0, 0, 0));
	ShowWindow(Result, SW_MAXIMIZE);
	return Result;
}

void WinMainCRTStartup(void)
{
	rpvgi__enable_process_dpi_awareness();
	HWND MainWindow = FindWindowW(FLARE_WNDCLASS_NAME, FLARE_WINDOW_TITLE);
	if(MainWindow)
	{
		WCHAR* Message = L"Flare is already running. Launch another instance?";
		UINT MessageType = MB_YESNO | MB_ICONINFORMATION;
		int Response = MessageBoxW(MainWindow, Message, FLARE_WINDOW_TITLE, MessageType);
		if(Response == IDNO)
		{
			goto label_program_exit;
		}
	}
	MainWindow = create_main_window();
	//CreateThread(0, 0, thread_renderer, MainWindow, 0, &THREAD_ID_RENDERER);
	//CreateThread(0, 0, thread_sound, MainWindow, 0, &THREAD_ID_SOUND);
	//CreateThread(0, 0, thread_renderer, MainWindow, 0, &THREAD_ID_);
	//CreateThread(0, 0, thread_renderer, MainWindow, 0, &THREAD_ID_);
	//CreateThread(0, 0, thread_renderer, MainWindow, 0, &THREAD_ID_);

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

	//config_save(AppConfig);
	//PostThreadMessageW(THREAD_ID_RENDERER, WM_QUIT, 0, 0);
	//PostThreadMessageW(THREAD_ID_RENDERER, WM_QUIT, 0, 0);
	//PostThreadMessageW(THREAD_ID_RENDERER, WM_QUIT, 0, 0);
	//PostThreadMessageW(THREAD_ID_RENDERER, WM_QUIT, 0, 0);
label_program_exit:
	ExitProcess(0);
}
