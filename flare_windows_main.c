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

void WinMainCRTStartup(void)
{
	rpvgi__enable_process_dpi_awareness();
	HWND MainWindow = FindWindowW(WNDCLASS_NAME, WINDOW_TITLE);
	if(MainWindow)
	{
		WCHAR* Message = L"Flare is already running. Launch another instance?";
		UINT MessageType = MB_YESNO | MB_ICONINFORMATION;
		int Response = MessageBoxW(MainWindow, Message, WINDOW_TITLE, MessageType);
		if(Response == IDNO)
		{
			goto label_program_exit;
		}
	}
	MainWindow = create_main_window();
	CreateThread(0, 0, thread_renderer, MainWindow, 0, &THREAD_ID_RENDERER);
	CreateThread(0, 0, thread_sound, 0, 0, &THREAD_ID_SOUND);
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
