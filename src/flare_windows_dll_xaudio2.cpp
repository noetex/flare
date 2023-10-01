#include<xaudio2.h>

BOOL WINAPI
_DllMainCRTStartup(HINSTANCE, DWORD CallReason, LPVOID)
{
	return TRUE;
	switch(CallReason)
	{
		case DLL_PROCESS_ATTACH:
		{

		} break;
		case DLL_PROCESS_DETACH:
		{

		} break;
		case DLL_THREAD_ATTACH:
		{

		} break;
		case DLL_THREAD_DETACH:
		{

		} break;
	}
}
