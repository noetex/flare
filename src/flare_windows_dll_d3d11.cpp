#define WIN32_LEAN_AND_MEAN
#include<windows.h>
#include<dxgi.h>
#include<d3d11.h>
#include<d3d11_1.h>

#pragma comment(lib, "kernel32.lib")

static HMODULE D3D11_MODULE;


#if 0
static IDXGISwapChain1*
d3d11_swapchain_create(HWND Window, size_t NumBuffers, ID3D11Device1* Device)
{
	RECT WindowRect;
	GetClientRect(Window, &WindowRect);
	LONG WindowWidth = WindowRect.right - WindowRect.left;
	LONG WindowHeight = WindowRect.bottom - WindowRect.top;
	DXGI_SWAP_CHAIN_DESC1 SwapChainInfo = {0};
	SwapChainInfo.Width = WindowWidth;
	SwapChainInfo.Height = WindowHeight;
	SwapChainInfo.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	SwapChainInfo.SampleDesc.Count = 1;
	SwapChainInfo.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	SwapChainInfo.BufferCount = 2;
	SwapChainInfo.Scaling = DXGI_SCALING_STRETCH;
	SwapChainInfo.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	SwapChainInfo.AlphaMode = DXGI_ALPHA_MODE_UNSPECIFIED;

	IDXGIDevice1* DxgiDevice;
	IDXGIAdapter* Adapter;
	IDXGIFactory2* Factory;
	IDXGISwapChain1* Result;
	Device->QueryInterface(__uuidof(IDXGIDevice1), (void**)&DxgiDevice);
	DxgiDevice->GetAdapter(&Adapter);
	Adapter->GetParent(__uuidof(IDXGIFactory2), (void**)&Factory);
	Factory->CreateSwapChainForHwnd(Device, Window, &SwapChainInfo, 0, 0, &Result);
	return Result;
}

CPP_API d3d11_renderer
d3d11_renderer_create(HWND Window)
{
	ID3D11Device* BaseDevice;
	ID3D11DeviceContext* BaseDeviceContext;
	D3D_DRIVER_TYPE Type = D3D_DRIVER_TYPE_HARDWARE;
	D3D_FEATURE_LEVEL Features[] = { D3D_FEATURE_LEVEL_11_0 };
	UINT Flags = D3D11_CREATE_DEVICE_SINGLETHREADED | D3D11_CREATE_DEVICE_BGRA_SUPPORT;
	D3D11CreateDevice(0, Type, 0, Flags, Features, array_length(Features), D3D11_SDK_VERSION, &BaseDevice, 0, &BaseDeviceContext);
	d3d11_renderer Result = {0};
	BaseDevice->QueryInterface(__uuidof(ID3D11Device1), (void**)&Result.Device);
	BaseDeviceContext->QueryInterface(__uuidof(ID3D11DeviceContext1), (void**)&Result.DeviceContext);
	Result.SwapChain = d3d11_swapchain_create(Window, 2, Result.Device);
	ID3D11Texture2D* Framebuffer;
	Result.SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&Framebuffer);
	Result.Device->CreateRenderTargetView(Framebuffer, 0, &Result.RenderTargetView);
	return Result;
}

CPP_API void
d3d11_renderer_destroy(d3d11_renderer* Renderer)
{
	if(Renderer->RenderTargetView)
	{
		Renderer->RenderTargetView->Release();
	}
	if(Renderer->SwapChain)
	{
		Renderer->SwapChain->Release();
	}
	if(Renderer->DeviceContext)
	{
		Renderer->DeviceContext->Release();
	}
	if(Renderer->Device)
	{
		Renderer->Device->Release();
	}
	d3d11_renderer Empty = {0};
	*Renderer = Empty;
}
#endif


BOOL WINAPI
DllMain(HINSTANCE Instance, DWORD CallReason, LPVOID Reserved)
{
	switch(CallReason)
	{
		case DLL_PROCESS_ATTACH:
		{
			D3D11_MODULE = LoadLibraryA("d3d11.dll");
			if(!D3D11_MODULE)
			{
				return FALSE;
			}
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
	return TRUE;
}
