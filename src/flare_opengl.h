#ifndef APIENTRY
	#ifdef FLARE_SYSTEM_WINDOWS
		#define APIENTRY WINAPI
	#else
		#define APIENTRY
	#endif
#endif

#define APIENTRYP APIENTRY*
//#define GLAPI

static_assert(sizeof(uint8_t) == 1);
static_assert(sizeof(uint16_t) == 2);
static_assert(sizeof(uint32_t) == 4);
static_assert(sizeof(uint64_t) == 8);
static_assert(sizeof(float) == 4);
static_assert(sizeof(double) == 8);

typedef char GLchar;
typedef uint8_t GLboolean;
typedef int8_t GLbyte;
typedef uint8_t GLubyte;
typedef int16_t GLshort;
typedef uint16_t GLushort;
typedef int32_t GLint;
typedef uint32_t GLuint;
typedef int32_t GLfixed;
typedef int64_t GLint64;
typedef uint64_t GLuint64;
typedef int32_t GLsizei;
typedef int32_t GLenum;
typedef intptr_t GLintptr;
typedef intptr_t GLsizeiptr;
typedef intptr_t GLsync;
typedef int32_t GLbitfield;
typedef int16_t GLhalf;
typedef float GLfloat;
typedef float GLclampf;
typedef double GLdouble;
typedef double GLclampd;
typedef void (APIENTRY *GLDEBUGPROC)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);

static void* query_opengl_function(char*);
#define QUERY_OPENGL_FUNCTION(Name) (Name = query_opengl_function(#Name))
