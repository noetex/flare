#include<vulkan/vulkan.h>


BOOL WINAPI
_DllMainCRTStartup(HINSTANCE, DWORD CallReason, LPVOID Reserved)
{
	return TRUE;
	switch(CallReason)
	{
		case DLL_PROCESS_ATTACH:
		{
		} break;
		case DLL_THREAD_DETACH:
		{
		} break;
		case DLL_THREAD_ATTACH:
		{

		} break;
		case DLL_PROCESS_DETACH:
		{

		} break;
	}
}
