#ifdef FLARE_SYSTEM_WINDOWS
	#include<windows.h>
	#include"system_windows.h"
	#include"system_windows_resource.h"
#else
	#error unspecified or unsupported operating system
#endif

#define STB_IMAGE_IMPLEMENTATION
#include"3rd_party/stb/stb_image.h"

#define NUKLEAR_IMPLEMENTATION
#include"3rd_party/nuklear/nuklear.h"

#define MINIAUDIO_IMPLEMENTATION
#include"3rd_party/miniaudio/miniaudio.h"


#include"flare.h"

#ifdef FLARE_SYSTEM_WINDOWS
	#include"src/windows_thread_main.cpp"
#endif
