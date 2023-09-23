static BITMAPINFO WINGDI_BITMAPINFO =
{
	.bmiHeader.biSize = sizeof(BITMAPINFOHEADER),
	.bmiHeader.biPlanes = 1,
	.bmiHeader.biBitCount = 32,
	.bmiHeader.biCompression = BI_RGB,
};

static void
renderer_resize(void)
{

}

static void
renderer_update(void)
{
	
}

static bool_t
process_renderer_messages(void)
{
	MSG ThreadMessage;
	while(PeekMessageW(&ThreadMessage, 0, 0, 0, PM_REMOVE))
	{
		switch(ThreadMessage.message)
		{
			case WM_CLOSE:
			case WM_DESTROY:
			{
				return true;
			} break;
		}
	}
	return false;
}

static DWORD WINAPI
thread_renderer(void* Parameter)
{
	HWND Window = Parameter;
	HDC WindowDC = GetDC(Window);
	HDC MemoryDC = CreateCompatibleDC(WindowDC);
	//HBITMAP BitmapHandle = CreateDIBSection();

	//d3d11_renderer Renderer = d3d11_renderer_create(Window);
	WaitMessage();
	for(;;)
	{
		bool_t ShouldQuit = process_renderer_messages();
		if(ShouldQuit)
		{
			break;
		}
	}
	PostMessageW(Window, WM_QUIT, 0, 0);
	return 0;
}
