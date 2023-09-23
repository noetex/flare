#ifdef _DEBUG
	#define FLARE_BUILD_DEBUG
#endif

#ifndef DPI_ENUMS_DECLARED
	typedef enum
	{
		PROCESS_DPI_UNAWARE = 0,
		PROCESS_SYSTEM_DPI_AWARE = 1,
		PROCESS_PER_MONITOR_DPI_AWARE = 2
	} PROCESS_DPI_AWARENESS;
	typedef enum
	{
		MDT_EFFECTIVE_DPI = 0,
		MDT_ANGULAR_DPI = 1,
		MDT_RAW_DPI = 2,
		MDT_DEFAULT = MDT_EFFECTIVE_DPI
	} MONITOR_DPI_TYPE;
#endif

#ifndef _DPI_AWARENESS_CONTEXTS_
	DECLARE_HANDLE(DPI_AWARENESS_CONTEXT);
	#define DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE (DPI_AWARENESS_CONTEXT)-3
#endif

#ifndef DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE
	#define DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE ((DPI_AWARENESS_CONTEXT)-3)
#endif

#ifndef DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2
	#define DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2 ((DPI_AWARENESS_CONTEXT)-4)
#endif

#define FLARE_WINDOW_TITLE L"Flare"
#define FLARE_WNDCLASS_NAME L"flare_wndclass"
#define WINDOW_TOOLBAR_WIDTH 150
#define VIEWPORT_MARGIN_X 20
#define VIEWPORT_MARGIN_Y 20


#define INI_SECTION_VIDEO L"Video"
#define INI_SECTION_AUDIO L"Audio"
#define INI_SECTION_INPUT L"Input"
#define INI_SECTION_GENERAL L"General"

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
