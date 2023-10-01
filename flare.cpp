#ifdef FLARE_SYSTEM_WINDOWS
	#include<windows.h>
	#include"system_windows.h"
	#include"system_windows_resource.h"
#else
	#error unspecified or unsupported operating system
#endif

#include"flare.h"

#ifdef FLARE_SYSTEM_WINDOWS
	#include"src/windows_thread_main.cpp"
#endif
