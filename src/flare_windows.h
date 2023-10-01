#define WINDOW_TOOLBAR_WIDTH 150
#define VIEWPORT_MARGIN_X 20
#define VIEWPORT_MARGIN_Y 20

enum window_menu_items
{
	MENUITEM_FILE_OPEN = 0x8000,
	MENUITEM_CONFIG_VIDEO,
	MENUITEM_CONFIG_AUDIO,
	MENUITEM_CONFIG_INPUT,
	MENUITEM_MISC_ABOUT,
};

enum
{
	WM_FLARE_CUSTOM_MESSAGE_1 = WM_APP,
	WM_FLARE_CUSTOM_MESSAGE_2,
	WM_FLARE_CUSTOM_MESSAGE_3,
	WM_FLARE_CUSTOM_MESSAGE_4,
	WM_FLARE_CUSTOM_MESSAGE_5,
};

static DWORD THREAD_ID_LOGGING;
static DWORD THREAD_ID_SOUND;
static DWORD THREAD_ID_INPUT;
static DWORD THREAD_ID_RENDERER;

static WCHAR PROGRAM_FILENAME[MAX_PATH];
static HINSTANCE PROGRAM_HINSTANCE;

static WCHAR WINDOW_TITLE[] = L"Flare";
static WCHAR WNDCLASS_NAME[] = L"flare_wndclass";

static WCHAR INI_SECTION_VIDEO[] = L"Video";
static WCHAR INI_SECTION_AUDIO[] = L"Audio";
static WCHAR INI_SECTION_INPUT[] = L"Input";
static WCHAR INI_SECTION_GENERAL[] = L"General";
