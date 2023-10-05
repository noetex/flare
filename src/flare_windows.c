static HMODULE
load_system_dll(char* Name)
{
	HMODULE Result = GetModuleHandleA(Name);
	if(!Result)
	{
		Result = LoadLibraryExA(Name, 0, LOAD_LIBRARY_SEARCH_SYSTEM32);
	}
	return Result;
}

static void
enable_process_dpi_awareness(void)
{
	void* Function = GetProcAddress(SYSTEM_DLL_USER32, "SetProcessDpiAwarenessContext");
	if(Function)
	{
		BOOL (*SetProcessDpiAwarenessContext)(HANDLE) = Function;
		HANDLE DpiAwarenessContextPerMonitorAwareV2 = (HANDLE)(-4);
		if(!SetProcessDpiAwarenessContext(DpiAwarenessContextPerMonitorAwareV2))
		{
			HANDLE DpiAwarenessContextPerMonitorAware = (HANDLE)(-3);
			SetProcessDpiAwarenessContext(DpiAwarenessContextPerMonitorAware);
		}
		return;
	}
	HMODULE ShellCore = LoadLibraryA("shcore.dll");
	Function = GetProcAddress(ShellCore, "SetProcessDpiAwareness");
	if(Function)
	{
		HRESULT (*SetProcessDpiAwareness)(enum DPI_PROCESS_AWARENESS) = Function;
		enum DPI_PROCESS_AWARENESS PROCESS_PER_MONITOR_DPI_AWARE = 2;
		SetProcessDpiAwareness(PROCESS_PER_MONITOR_DPI_AWARE);
		return;
	}
	FreeLibrary(ShellCore);
	Function = GetProcAddress(SYSTEM_DLL_USER32, "SetProcessDPIAware");
	if(Function)
	{
		BOOL (*SetProcessDPIAware)(void) = Function;
		SetProcessDPIAware();
	}
}

static bool_t
system_is_64bit(void)
{
	void* Function = GetProcAddress(SYSTEM_DLL_KERNEL32, "IsWow64Process2");
	if(Function)
	{
		USHORT ProcessMachine, NativeMachine;
		HANDLE ProcessHandle = GetCurrentProcess();
		BOOL (*IsWow64Process2)(HANDLE, USHORT*, USHORT*) = Function;
		IsWow64Process2(ProcessHandle, &ProcessMachine, &NativeMachine);
		bool_t Result = (NativeMachine == IMAGE_FILE_MACHINE_AMD64);
		return Result;
	}
#if 0
	Function = GetProcAddress(Kernel32, "IsWow64Process");
	if(Function)
	{
		BOOL Is64Bit;
		BOOL (IsWow64Process)(HANDLE, BOOL*);
		IsWow64Process(ProcessHandle, &Is64Bit);
		bool_t Result = Is64Bit;
		return Result;
	}
#endif
	SYSTEM_INFO SystemInfo;
	GetNativeSystemInfo(&SystemInfo);
	bool_t Result = (SystemInfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64) || (SystemInfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_IA64);
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
