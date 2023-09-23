#ifdef FLARE_SYSTEM_WINDOWS
	#define NOMINMAX
	#define WIN32_LEAN_AND_MEAN
	#include<windows.h>
	#include<shlwapi.h>
	#include<pathcch.h>
	#include<shellscalingapi.h>
	#include"flare_windows.h"
	#include"flare_windows_resource.h"
#elif defined(FLARE_SYSTEM_LINUX) || defined(FLARE_SYSTEM_MACOS)
	#include<unistd.h>
	#include<termios.h>
	#include<fcntl.h>
	#include<sys/time.h>
	#include<sys/types.h>
	#include<sys/ioctl.h>
	#ifdef FLARE_SYSTEM_LINUX
		#include"flare_linux.h"
	#else
		#include"flare_macos.h"
	#endif
#elif defined FLARE_SYSTEM_HAIKU
	#include"flare_haiku.h"
#else
	#error unspecified or unsupported operating system.
#endif

#include<math.h>
#include<stdint.h>
//#include<time.h>
//#include<tgmath.h>
//#include<signal.h>
//#include<errno.h>
//#include<ctype.h>
//#include<string.h>
//#include<stdio.h>
//#include<stdarg.h>
//#include<stdlib.h>

#include"flare.h"

#ifdef FLARE_SYSTEM_WINDOWS
	#include"flare_windows_thread_sound.c"
	#include"flare_windows_thread_renderer.c"
	#include"flare_windows_main.c"
#elif defined FLARE_SYSTEM_LINUX
	#include"flare_linux_main.c"
#elif defined FLARE_SYSTEM_MACOS
	#include"flare_macos_main.c"
#elif defined FLARE_SYSTEM_HAIKU
	#include"flare_haiku_main.c"
#endif
