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
	#define debug_break() __builtin_trap()
	#define ALIGNED(Alignment) __attribute__((aligned(Alignment)))
#else
	#error Unsupported compiler.
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
	#define static_assert(Expr, Msg) typedef int static_assert_typedef[(!!(Expr)) ? 1 : -1]
	//#define static_assert(Expr, Msg) _Static_assert(Expr, Msg)
	enum { false = 0, true = !false };
#endif

#define FLOAT_TOLERANCE_DEFAULT 0.00001f
#define array_length(Array) (sizeof(Array)/sizeof(*(Array)))
#define float_cmp_equal(A, B) (fabs((A) - (B)) < FLOAT_TOLERANCE_DEFAULT)
#define float_cmp_zero(Value) (fabs(Value) < FLOAT_TOLERANCE_DEFAULT)
#define sign(Value) (((Value) > 0) ? 1 : ((Value) < 0) ? -1 : 0)

//#define log_info(Message)
//#define log_debug(Message)
//#define log_error(Message)
//#define log_warning(Message)

typedef int bool_t;
typedef float float32_t;
typedef double float64_t;
typedef float32_t real_t;

enum log_severity
{
	LOG_SEVERITY_INFO,
	LOG_SEVERITY_WARNING,
	LOG_SEVERITY_ERROR,
	LOG_SEVERITY_DEBUG,
};
