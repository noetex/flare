typedef struct
{
	bool_t CrashedLastTime;
} flare_config;

static flare_config FLARE_CONFIG_DEFAULT = {0};

static flare_config
config_load(void)
{
	WCHAR ConfigFileName[MAX_PATH] = {0};
	GetModuleFileNameW(0, ConfigFileName, array_length(ConfigFileName));
	PathCchRenameExtension(ConfigFileName, array_length(ConfigFileName), L".ini");
	if(!PathFileExistsW(ConfigFileName))
	{
		return FLARE_CONFIG_DEFAULT;
	}
	flare_config Result = {0};
	WritePrivateProfileStringW(INI_SECTION, L"Key1", L"String1", ConfigFileName);
	WritePrivateProfileStringW(INI_SECTION, L"Key2", L"String2", ConfigFileName);
	WritePrivateProfileStringW(INI_SECTION, L"Key3", L"String3", ConfigFileName);
	WritePrivateProfileStringW(INI_SECTION, L"Key4", L"String4", ConfigFileName);
	bool_t ShutDownProperly = GetPrivateProfileIntW(INI_SECTION, L"ShutDownProperly", -1, ConfigFileName);
#if 0
	DWORD GetPrivateProfileStringW(INI_SECTION, "Key1", ""
  [in]  LPCWSTR lpAppName,
  [in]  LPCWSTR lpKeyName,
  [in]  LPCWSTR lpDefault,
  [out] LPWSTR  lpReturnedString,
  [in]  DWORD   nSize,
  [in]  LPCWSTR lpFileName
	);
#endif
	return Result;
}
