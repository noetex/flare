typedef struct ID3D11Device1* d3d11_device;
typedef struct ID3D11DeviceContext1* d3d11_devicecontext;
typedef struct ID3D11RenderTargetView* d3d11_rendertargetview;
typedef struct ID3D11PixelShader* d3d11_pixelshader;
typedef struct ID3D11VertexShader* d3d11_vertexshader;

typedef struct IDXGISwapChain1* dxgi_swapchain;
typedef struct IDXGIFactory2* dxgi_factory;

typedef struct
{
	dxgi_swapchain SwapChain;
	d3d11_device Device;
	d3d11_devicecontext DeviceContext;
	d3d11_rendertargetview RenderTargetView;
} d3d11_renderer;

CPP_API d3d11_renderer d3d11_renderer_create(HWND);
CPP_API void d3d11_renderer_destroy(d3d11_renderer* Renderer);
