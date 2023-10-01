#ifdef FLARE_SYSTEM_WINDOWS
	#define NOMINMAX
	#define WIN32_LEAN_AND_MEAN
	#include<windows.h>
	#include"src/windows.h"
	#include"src/windows_resource.h"
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

#define GLEW_STATIC
#include"3rd_party/glew-2.2.0/include/GL/glew.h"

#define STB_IMAGE_IMPLEMENTATION
#include"3rd_party/stb/stb_image.h"

#define NUKLEAR_IMPLEMENTATION
#include"3rd_party/nuklear/nuklear.h"

#define MINIAUDIO_IMPLEMENTATION
#include"3rd_party/miniaudio/miniaudio.h"


#include"flare.h"

#ifdef FLARE_SYSTEM_WINDOWS
	#include"3rd_party/rpvgi/rpvgi_windows_commons.c"
	#include"windows_thread_sound.c"
	#include"windows_thread_renderer.c"
	#include"windows_thread_main.c"
#elif defined FLARE_SYSTEM_LINUX
	#include"flare_linux_main.c"
#elif defined FLARE_SYSTEM_MACOS
	#include"flare_macos_main.c"
#elif defined FLARE_SYSTEM_HAIKU
	#include"flare_haiku_main.c"
#endif
