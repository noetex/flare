#ifdef FLARE_SYSTEM_WINDOWS
	#define NOMINMAX
	#define WIN32_LEAN_AND_MEAN
	#include<windows.h>
	#include<pathcch.h>
	#include"flare_windows.h"
	#include"flare_windows_resource.h"
#else
	#error unspecified or unsupported operating system.
#endif

#define _USE_MATH_DEFINES
#include<math.h>
#include<string.h>
#include<stdint.h>

#include"flare.h"
#include"flare_opengl.h"
#include"flare_opengl_core.h"
#include"flare_math_vector.h"
#include"flare_math_matrix.h"
#include"flare_camera.h"

#include"flare_misc.c"
#include"flare_opengl_core.c"

#ifdef FLARE_SYSTEM_WINDOWS
	#include"flare_windows.c"
	//#include"flare_windows_thread_renderer.c"
	#include"flare_windows_thread_main.c"
#endif
