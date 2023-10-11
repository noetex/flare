#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "pathcch.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "3rd_party/glew-2.2.0/lib/Release/x64/glew32s.lib")

enum
{
	WM_FLARE_CUSTOM_MESSAGE_1 = WM_APP,
	WM_FLARE_CUSTOM_MESSAGE_2,
	WM_FLARE_CUSTOM_MESSAGE_3,
	WM_FLARE_CUSTOM_MESSAGE_4,
	WM_FLARE_CUSTOM_MESSAGE_5,
};

enum
{
	HID_USAGE_PAGE_GENERIC = 0x01,
	HID_USAGE_PAGE_GAME = 0x05,
	HID_USAGE_PAGE_LED = 0x08,
	HID_USAGE_PAGE_BUTTON = 0x09,
};

enum
{
	HID_USAGE_GENERIC_POINTER = 0x01,
	HID_USAGE_GENERIC_MOUSE = 0x02,
	HID_USAGE_GENERIC_JOYSTICK = 0x04,
	HID_USAGE_GENERIC_GAMEPAD = 0x05,
	HID_USAGE_GENERIC_KEYBOARD = 0x06,
	HID_USAGE_GENERIC_KEYPAD = 0x07,
	HID_USAGE_GENERIC_MULTI_AXIS_CONTROLLER = 0x08,
};

static DWORD THREAD_ID_LOGGING;
static DWORD THREAD_ID_SOUND;
static DWORD THREAD_ID_INPUT;
static DWORD THREAD_ID_RENDERER;

static HINSTANCE PROGRAM_HINSTANCE;

static HMODULE SYSTEM_DLL_KERNEL32;
static HMODULE SYSTEM_DLL_USER32;

static BOOL SYSTEM_IS_64BITS;

static LARGE_INTEGER PROCESSOR_FREQUENCY;

static WCHAR FILENAME_EXE[MAX_PATH];
static WCHAR FILENAME_INI[MAX_PATH];
static WCHAR FILENAME_LOG[MAX_PATH];

static WCHAR WINDOW_TITLE[] = L"Flare";
static WCHAR WNDCLASS_NAME[] = L"flare_wndclass";

static WCHAR INI_SECTION_GRAPHICS[] = L"Video";
static WCHAR INI_SECTION_AUDIO[] = L"Audio";
static WCHAR INI_SECTION_INPUT[] = L"Input";
static WCHAR INI_SECTION_GENERAL[] = L"General";

static WCHAR INI_KEY_GRAPHICS_API[] = L"API";
static WCHAR INI_KEY_GENERAL_SAFEEXIT[] = L"SafeExit";

static WCHAR INI_VALUE_TRUE[] = L"1";
static WCHAR INI_VALUE_FALSE[] = L"0";
static WCHAR INI_VALUE_GRAPHICS_D3D11[] = L"Direct3D 11";
static WCHAR INI_VALUE_GRAPHICS_D3D12[] = L"Direct3D 12";
static WCHAR INI_VALUE_GRAPHICS_OPENGL[] = L"OpenGL";
static WCHAR INI_VALUE_GRAPHICS_VULKAN[] = L"Vulkan";
