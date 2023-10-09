#ifdef FLARE_SYSTEM_WINDOWS
	#include<windows.h>
	#include"flare_windows.h"
	#include"flare_windows_resource.h"
#else
	#error unspecified or unsupported operating system
#endif

#include"flare.h"
#include"flare_camera.hpp"

#ifdef FLARE_SYSTEM_WINDOWS
	#include"flare_windows_main.cpp"
#endif
