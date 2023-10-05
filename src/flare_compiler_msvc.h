#define FORCE_INLINE __forceinline
#define DLL_EXPORT __declspec(dllexport)
#define DLL_IMPORT __declspec(dllimport)
#define CALLING_CONVENTION_CDECL __cdecl
#define CALLING_CONVENTION_STDCALL __stdcall
#define debug_break(...) __debugbreak()
#define ALIGNED(Alignment) __declspec(align(Alignment))


typedef struct
{
	int32_t EAX;
	int32_t EBX;
	int32_t ECX;
	int32_t EDX;
} x86_64_cpuid_struct;

static void
x86_64_cpuid(int32_t EAX, int32_t ECX)
{
	__asm
	{
		mov eax, EAX
		mov ecx, ECX
		cpuid
		mov eax, Result.EAX
		mov ebx, Result.EBX
		mov ecx, Result.ECX
		mov edx, Result.EDX
	};
}
