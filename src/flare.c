#ifdef FLARE_SYSTEM_WINDOWS
	#define NOMINMAX
	#define WIN32_LEAN_AND_MEAN
	#include<windows.h>
	#include<shlwapi.h>
	#include"flare_windows.h"
#else
	#error unspecified or unsupported operating system.
#endif

#define GLEW_STATIC
#include"../3rd_party/glew-2.2.0/include/GL/glew.h"

#include<string.h>

#include"flare.h"

#include"flare_misc.c"

#ifdef FLARE_SYSTEM_WINDOWS
	#include"flare_windows.c"
	#include"flare_windows_thread_main.c"
#endif
