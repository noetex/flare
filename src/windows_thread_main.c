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

void WinMainCRTStartup(void)
{
	SYSTEM_DLL_KERNEL32 = load_system_dll("kernel32.dll");
	SYSTEM_DLL_USER32 = load_system_dll("user32.dll");
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

	WCHAR ConfigFileName[MAX_PATH] = {0};
	GetModuleFileNameW(0, ConfigFileName, ARRAYSIZE(ConfigFileName));
	PathRenameExtensionW(ConfigFileName, L".ini");
	UINT SafeExit = GetPrivateProfileIntW(INI_SECTION_GENERAL, INI_KEY_GENERAL_SAFEEXIT, 0, ConfigFileName);


	WNDCLASSEXW WindowClass = {0};
	WindowClass.cbSize = sizeof(WindowClass);
	WindowClass.lpfnWndProc = window_proc;
	WindowClass.lpszClassName = WNDCLASS_NAME;
	RegisterClassExW(&WindowClass);
	Window = CreateWindowExW(0, WNDCLASS_NAME, WINDOW_TITLE, WS_OVERLAPPEDWINDOW, 0, 0, 0, 0, 0, 0, 0, 0);
	HDC WindowDC = GetDC(Window);

	ShowWindow(Window, SW_MAXIMIZE);

	MSG Message;
	while(GetMessageW(&Message, 0, 0, 0))
	{
		TranslateMessage(&Message);
		DispatchMessageW(&Message);
	}
	WritePrivateProfileStringW(INI_SECTION_GENERAL, INI_KEY_GENERAL_SAFEEXIT, L"1", ConfigFileName);
	WritePrivateProfileStringW(INI_SECTION_GRAPHICS, INI_KEY_GRAPHICS_API, L"1", ConfigFileName);
label_program_exit:
	ExitProcess(0);
}
