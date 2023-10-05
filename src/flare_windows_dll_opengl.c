#define WIN32_LEAN_AND_MEAN
#include<windows.h>
#include<stdint.h>

#include"flare.h"
#include"3rd_party/khrplatform.h"
#include"3rd_party/glad.h"
#include"3rd_party/glad.c"

#if 0
#include"flare_api_opengl.h"
#include"flare_api_opengl_core_1_0.h"
#include"flare_api_opengl_core_1_1.h"
#include"flare_api_opengl_core_1_2.h"
#include"flare_api_opengl_core_1_3.h"
#include"flare_api_opengl_core_1_4.h"
#include"flare_api_opengl_core_1_5.h"
#include"flare_api_opengl_core_2_0.h"
#include"flare_api_opengl_core_2_1.h"
#include"flare_api_opengl_core_3_0.h"
#include"flare_api_opengl_core_3_1.h"
#include"flare_api_opengl_core_3_1.h"
#include"flare_api_opengl_core_3_3.h"
#include"flare_api_opengl_core_4_0.h"
#include"flare_api_opengl_core_4_1.h"
#include"flare_api_opengl_core_4_2.h"
#include"flare_api_opengl_core_4_3.h"
#include"flare_api_opengl_core_4_4.h"
#include"flare_api_opengl_core_4_5.h"
#include"flare_api_opengl_core_4_6.h"
#include"flare_api_opengl.c"
#endif

#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "libucrtd.lib")

static HMODULE OPENGL_MODULE;

static PIXELFORMATDESCRIPTOR OPENGL_PFD =
{
	.nVersion = 1,
	.cColorBits = 24,
	.cDepthBits = 32,
	.cStencilBits = 8,
	.iPixelType = PFD_TYPE_RGBA,
	.nSize = sizeof(PIXELFORMATDESCRIPTOR),
	.dwFlags = PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW | PFD_DOUBLEBUFFER,
};

DLL_EXPORT void*
opengl_platform_queryfunction(char* Name)
{
	void* Result = wglGetProcAddress(Name);
	intptr_t Address = (intptr_t)Result;
	if((Address >= -1) && (Address <= 0x3))
	{
		Result = GetProcAddress(OPENGL_MODULE, Name);
		Assert(Result);
	}
	return Result;
}

DLL_EXPORT void
opengl_platform_init(void* Parameter, char** UserErrorPtr)
{
	DWORD ErrorCode;
	char* ErrorMessage = 0;
	HWND Window = Parameter;
	OPENGL_MODULE = LoadLibraryA("opengl32.dll");
	HDC WindowDC = GetDC(Window);
	if(!WindowDC)
	{
		//ErrorCode = GetLastError();
		"[WIN32] GetDC() failed: "
		"Could not obtain the device"
		"context of the specified window.";
		debug_break();
		goto label_function_exit;
	}
	int PixelFormat = ChoosePixelFormat(WindowDC, &OPENGL_PFD);
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
		"[NOTE] Windows only allows setting "
		"a window's pixel format once."
		"In that case, recreating the window"
		"will solve the issue.";
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

DLL_EXPORT void
opengl_platform_destroy(void* Parameter)
{
	HWND Window = Parameter;
	HDC WindowDC = GetDC(Window);
	HGLRC OpenGLContext = wglGetCurrentContext();
	wglMakeCurrent(WindowDC, 0);
	wglDeleteContext(OpenGLContext);
	FreeLibrary(OPENGL_MODULE);
}

extern BOOL WINAPI
_DllMainCRTStartup(HINSTANCE Instance, DWORD CallReason, LPVOID Reserved)
{
	BOOL Result = TRUE;
	switch(CallReason)
	{
		case DLL_PROCESS_ATTACH:
		{
			OPENGL_MODULE = LoadLibraryA("opengl32.dll");
			if(!OPENGL_MODULE)
			{
				DWORD ErrorCode = GetLastError();
				WCHAR Message[] =
				{
					L"The library opengl32.dll is missing from the system.\n"
					L"Please install the latest graphics drivers;"
					L"either from Windows Update, or your"
					L"graphics card manufacturer's website."
					L"Win32 error code: %d"
				};
				MessageBoxW(0, Message, 0, MB_OK | MB_ICONERROR);
				Result = FALSE;
			}
		} break;
		case DLL_PROCESS_DETACH:
		{
			FreeLibrary(OPENGL_MODULE);
		} break;
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		{} break;
	}
	return Result;
}
