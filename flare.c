#ifdef FLARE_SYSTEM_WINDOWS
	#define NOMINMAX
	#define WIN32_LEAN_AND_MEAN
	#include<windows.h>
	#include"src/windows.h"
	#include"src/windows_resource.h"
#else
	#error unspecified or unsupported operating system.
#endif

#include"flare.h"

#ifdef FLARE_SYSTEM_WINDOWS
	#include"windows_thread_main.c"
#endif
