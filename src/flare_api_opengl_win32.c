#include<wingdi.h>
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "opengl32.lib")

static HMODULE OPENGL_MODULE;

static PIXELFORMATDESCRIPTOR OPENGL_PFD =
{
	.Version = 1,
	.cColorBits = 24,
	.cDepthBits = 32,
	.cStencilBits = 8,
	.iPixelType = PFD_TYPE_RGBA,
	.nSize = sizeof(PIXELFORMATDESCRIPTOR),
	.dwFlags = PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW | PFD_DOUBLEBUFFER,
};

void* __declspec(dllexport)
opengl_platform_queryfunction(char* Name)
{
	void* Result = wglGetProcAddress(Name);
	intptr_t Address = (intptr_t)Result;
	if((Address >= -1) && (Address <= 0x3))
	{
		Result = GetProcAddress(OPENGL_MODULE, Name);
		assert_debug(Result);
	}
	return Result;
}

void __declspec(dllexport)
opengl_platform_init(void* Parameter, char** UserErrorPtr)
{
	char* ErrorMessage = 0;
	HWND Window = Parameter;
	OPENGL_MODULE = LoadLibraryA("opengl32.dll");
	HDC WindowDC = GetDC(Window);
	if(!WindowDC)
	{
		//DWORD ErrorCode = GetLastError();
		"[WIN32] GetDC() failed: "
		"Could not obtain the device"
		"context of the specified window.";
		debug_break();
		goto label_function_exit;
	}
	int PixelFormat = ChoosePixelFormat(DeviceContext, &OPENGL_PFD);
	if(!PixelFormat)
	{
		ErrorCode = GetLastError();
		"[WIN32] ChoosePixelFormat() failed: "
		"Could not match a pixel format of the given"
		"description to one that is supported by the"
		"specified device context."
		"Win32 error code: %d.";
		debug_break();
		goto label_function_exit;
	}
	if(!SetPixelFormat(WindowDC, PixelFormat, &OPENGL_PFD))
	{
		ErrorCode = GetLastError();
		"[WIN32] SetPixelFormat() failed: "
		"Could not set the specified pixel format."
		"Win32 error code: %d.";
		debug_break();
		goto label_function_exit;
	}
	if(!DescribePixelFormat(WindowDC, PixelFormat, sizeof(OPENGL_PFD), &OPENGL_PFD))
	{
		ErrorCode = GetLastError();
		"WIN32 DescribePixelFormat() failed:"
		"Something should be done."
		"Win32 error code: %d.";
		debug_break();
		goto label_function_exit;
	}
	HGLRC OpenGLContext = wglCreateContext(WindowDC);
	if(!OpenGLContext)
	{
		ErrorCode = GetLastError();
		"[WIN32] wglCreateContext() failed: "
		"Win32 error code: %d. ";
		debug_break();
		goto label_function_exit;
	}
	if(!wglMakeCurrent(WindowDC, OpenGLContext))
	{
		ErrorCode = GetLastError();
		"[WIN32] wglMakeCurrent() failed: "
		"Could not set OpenGL context as"
		"the current.";
		debug_break();
	}

label_function_exit:
	if(WindowDC)
	{
		ReleaseDC(Window, WindowDC);
	}
	if(UserErrorPtr)
	{
		*UserErrorPtr = ErrorMessage;
	}
}

void __declspec(dllexport)
opengl_platform_destroy(void* Parameter)
{
	HWND Window = Parameter;
	HDC WindowDC = GetDC(Window);
	HGLRC OpenGLContext = wglGetCurrentContext(WindowDC);
	wglMakeCurrent(WindowDC, 0);
	wglDeleteContext(OpenGLContext);
	FreeLibrary(OPENGL_MODULE);
}

BOOL WINAPI
DllMain(HINSTANCE Instance, DWORD CallReason, LPVOID Reserved)
{
	switch(CallReason)
	{
		case DLL_PROCESS_ATTACH:
		{
			OPENGL_MODULE = LoadLibraryA("opengl32.dll");
			if(!OPENGL_MODULE)
			{
				return FALSE;
			}
			if(Reserved)
			{
				// static load
			}
			else
			{
				// dynamic load
			}
			// Initialize once for each new process.
			// Return FALSE to fail DLL load.
		} break;
		case DLL_PROCESS_DETACH:
		{
			if(Reserved)
			{
				// process is terminating
				break;
			}
			else
			{
				// FreeLibrary() was called
				// Or DLL load failed
				// cleanup.
			}
		} break;
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		{
		} break;
	}
	return TRUE;
}
