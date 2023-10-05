static LRESULT CALLBACK
window_proc(HWND Window, UINT Message, WPARAM wParam, LPARAM lParam)
{
	LRESULT Result = 0;
	switch(Message)
	{
		case WM_CREATE:
		{
			RAWINPUTDEVICE Mouse = {0};
			Mouse.usUsagePage = HID_USAGE_PAGE_GENERIC;
			Mouse.usUsage = HID_USAGE_GENERIC_MOUSE;
			Mouse.dwFlags = RIDEV_NOLEGACY;
			Mouse.hwndTarget = Window;
			RegisterRawInputDevices(&Mouse, 1, sizeof(Mouse));
		} break;
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
	HDC WindowDC = GetDC(Window);
	HGLRC ContextGL = create_opengl_context(WindowDC);
	Assert(glewInit() == GLEW_OK);
	ShowWindow(Window, SW_MAXIMIZE);

	MSG Message;
	while(GetMessageW(&Message, 0, 0, 0))
	{
		TranslateMessage(&Message);
		DispatchMessageW(&Message);
	}
	WritePrivateProfileStringW(INI_SECTION_GENERAL, INI_KEY_GENERAL_SAFEEXIT, L"1", FILENAME_INI);
	WritePrivateProfileStringW(INI_SECTION_GRAPHICS, INI_KEY_GRAPHICS_API, L"1", FILENAME_INI);
label_program_exit:
	ExitProcess(0);
}
