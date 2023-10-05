#include<xinput.h>
static HMODULE XINPUT_MODULE;

BOOL WINAPI
_DllMainCRTStartup(HINSTANCE, DWORD CallReason, LPVOID)
{
	return TRUE;
	XINPUT_MODULE = LoadLibraryA("xinput_1_4.dll");
	switch(CallReason)
	{
		case DLL_PROCESS_ATTACH:
		{

		} break;
		case DLL_THREAD_ATTACH:
		{

		} break;
		case DLL_THREAD_DETACH:
		{

		} break;
		case DLL_PROCESS_DETACH:
		{

		} break;
	}
}
