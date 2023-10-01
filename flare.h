#ifdef FLARE_COMPILER_MSVC
	#define FORCE_INLINE __forceinline
	#define DLL_EXPORT __declspec(dllexport)
	#define DLL_IMPORT __declspec(dllimport)
	#define debug_break(...) __debugbreak()
	#define ALIGNED(Alignment) __declspec(align(Alignment))
#elif defined(FLARE_COMPILER_GCC) || defined(FLARE_COMPILER_CLANG)
	#define FORCE_INLINE __attribute__((always_inline))
	#define DLL_EXPORT __attribute__((dllexport))
	#define DLL_IMPORT __attribute__((dllimport))
	//#define DLL_IMPORT __attribute__((visibility("default")))
	#define debug_break(...) __builtin_trap()
	#define ALIGNED(Alignment) __attribute__((aligned(Alignment)))
#else
	#error unspecified or unsupported compiler.
#endif

#ifdef FLARE_BUILD_DEBUG
	#define Assert(Condition) if(Condition); else debug_break()
#else
	#define Assert(Condition) ((void)(Condition))
	#undef debug_break
#endif

#ifdef __cplusplus
	#define CPP_API extern "C"
	#define ASM_API extern "C"
	#define GLOBAL_FUNCTION extern "C"
#else
	#define CPP_API extern
	#define ASM_API extern
	#define GLOBAL_FUNCTION extern
	#define static_assert(Expr) typedef int static_assert_typedef[(!!(Expr)) ? 1 : -1]
	enum { false = 0, true = !false };
#endif

#ifndef ARRAYSIZE
	#define ARRAYSIZE(Array) (sizeof(Array)/sizeof((Array)[0]))
#endif

typedef int bool_t;
