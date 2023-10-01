#include<windows.h>
#include<d3d11.h>
#include<d3dcompiler.h>

static WCHAR WNDCLASS_NAME[] = L"wndclass";

float TRIANGLE_VERTS[] =
{
	-0.5f, -0.5f, 0.0f,
	0.0f, 0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
};

int WINAPI
WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	WNDCLASSEXW WindowClass = {0};
	WindowClass.cbSize = sizeof(WindowClass);
	WindowClass.lpfnWndProc = DefWindowProcW;
	WindowClass.lpszClassName = WNDCLASS_NAME;
	RegisterClassExW(&WindowClass);
	HWND Window = CreateWindowExW(0, WNDCLASS_NAME, 0, WS_POPUP | WS_MAXIMIZE | WS_VISIBLE, 0, 0, 0, 0, 0, 0, 0, 0);

	RECT WindowRect;
	GetClientRect(Window, &WindowRect);
	LONG WindowWidth = WindowRect.right - WindowRect.left;
	LONG WindowHeight = WindowRect.bottom - WindowRect.top;

	ID3D11Device* Device = 0;
	ID3D11DeviceContext* DeviceContext = 0;
	IDXGISwapChain* SwapChain = 0;
	D3D_FEATURE_LEVEL FeatureLevel = D3D_FEATURE_LEVEL_11_0;
	DXGI_SWAP_CHAIN_DESC SwapChainInfo = {0};
	SwapChainInfo.BufferDesc.RefreshRate.Numerator = 60;
	SwapChainInfo.BufferDesc.RefreshRate.Denominator = 1;
	SwapChainInfo.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM_SRGB;
	SwapChainInfo.SampleDesc.Count = 1;
	SwapChainInfo.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	SwapChainInfo.BufferCount = 2;
	SwapChainInfo.OutputWindow = Window;
	SwapChainInfo.Windowed = TRUE;
	SwapChainInfo.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	D3D11CreateDeviceAndSwapChain(0, D3D_DRIVER_TYPE_HARDWARE, 0, D3D11_CREATE_DEVICE_SINGLETHREADED, 0, 0, D3D11_SDK_VERSION, &SwapChainInfo, &SwapChain, &Device, 0, &DeviceContext);

	ID3D11Texture2D* Framebuffer = 0;
	ID3D11RenderTargetView* FramebufferView;
	SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&Framebuffer);
	Device->CreateRenderTargetView(Framebuffer, 0, &FramebufferView);

	ID3DBlob* ErrorBlob = 0;
	ID3DBlob* VertexShaderBlob = 0;
	ID3D11VertexShader* VertexShader = 0;
	D3DCompileFromFile(L"shaders.hlsl", 0, 0, "vs_main", "vs_5_0", 0, 0, &VertexShaderBlob, &ErrorBlob);
	Device->CreateVertexShader(VertexShaderBlob->GetBufferPointer(), VertexShaderBlob->GetBufferSize(), 0, &VertexShader);
	DeviceContext->VSSetShader(VertexShader, 0, 0);

	ID3D11InputLayout* InputLayout = 0;
	D3D11_INPUT_ELEMENT_DESC InputElementDesc[] =
	{
		{ "POS", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	};
	Device->CreateInputLayout(InputElementDesc, ARRAYSIZE(InputElementDesc), VertexShaderBlob->GetBufferPointer(), VertexShaderBlob->GetBufferSize(), &InputLayout);
	DeviceContext->IASetInputLayout(InputLayout);

	ID3DBlob* PixelShaderBlob = 0;
	ID3D11PixelShader* PixelShader = 0;
	D3DCompileFromFile(L"shaders.hlsl", 0, 0, "ps_main", "ps_5_0", 0, 0, &PixelShaderBlob, 0);
	Device->CreatePixelShader(PixelShaderBlob->GetBufferPointer(), PixelShaderBlob->GetBufferSize(), 0, &PixelShader);
	DeviceContext->PSSetShader(PixelShader, 0, 0);

	ID3D11Buffer* VertexBuffer = 0;
	D3D11_BUFFER_DESC VertexBufferDesc = {0};
	D3D11_SUBRESOURCE_DATA VertexResource = {0};
	VertexBufferDesc.ByteWidth = sizeof(TRIANGLE_VERTS);
	VertexBufferDesc.Usage = D3D11_USAGE_IMMUTABLE;
	VertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	VertexResource.pSysMem = TRIANGLE_VERTS;
	Device->CreateBuffer(&VertexBufferDesc, &VertexResource, &VertexBuffer);
	UINT VertexOffset = 0;
	UINT VertexStride = 3 * sizeof(float);
	DeviceContext->IASetVertexBuffers(0, 1, &VertexBuffer, &VertexStride, &VertexOffset);

	D3D11_VIEWPORT Viewport = {0};
	Viewport.Width = (FLOAT)WindowWidth;
	Viewport.Height = (FLOAT)WindowHeight;
	Viewport.MaxDepth = 1.0f;
	DeviceContext->RSSetViewports(1, &Viewport);

	FLOAT BackgroundColor[4] = { 0.025f, 0.025f, 0.025f, 1.0f };
	DeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	for(;;)
	{
		MSG Message;
		while(PeekMessageW(&Message, 0, 0, 0, PM_REMOVE))
		{
			if(Message.message == WM_KEYDOWN)
			{
				return 0;
			}
			DispatchMessageW(&Message);
		}
		DeviceContext->ClearRenderTargetView(FramebufferView, BackgroundColor);
		DeviceContext->Draw(3, 0);
		SwapChain->Present(1, 0);
	}
	return 0;
}
