#ifdef FLARE_SYSTEM_WINDOWS
	#define NOMINMAX
	#define WIN32_LEAN_AND_MEAN
	#include<windows.h>
	#include<shlwapi.h>
	#include"src/windows.h"
#else
	#error unspecified or unsupported operating system.
#endif

#define GLEW_STATIC
#include"3rd_party\glew-2.2.0\include\GL\glew.h"

#include"flare.h"

#include"src/misc.c"

#ifdef FLARE_SYSTEM_WINDOWS
	#include"src/windows.c"
	#include"src/windows_thread_main.c"
#endif
