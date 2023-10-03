@echo off

if /i "%1" equ "clean" (
	del *.obj *.exe *.pdb *.exp *.lib *.dll *.ilk *.res>nul
	exit /b 0
)

set exit_code=0
set target_files=flare.c
set lib_files=kernel32.lib user32.lib shlwapi.lib vcruntime.lib gdi32.lib opengl32.lib
set exe_filename=flare.exe

if /i "%1" equ "clang" goto label_build_clang

:label_build_msvc
set base_flags=/nologo /W3 /D FLARE_SYSTEM_WINDOWS /D FLARE_COMPILER_MSVC /I 3rd_party/imgui
set link_flags=/WX /incremental:no /opt:ref,icf /ignore:4099

if /i "%1" equ "release" (
	set base_flags=%base_flags% /O2
) else (
	set base_flags=%base_flags% /Zi /D FLARE_BUILD_DEBUG
)

rem set dll_flags=%base_flags% /LDd /link %link_flags%
set exe_flags=%base_flags% /link %link_flags% /subsystem:windows %lib_files%

rem call rc flare_windows_resource.rc /nologo /y /fo flare_resource.res
rem call cl flare_windows_dll_opengl.c /Fe:flare_opengl.dll %dll_flags%
rem call cl flare_windows_dll_vulkan.c /Fe:flare_vulkan.dll %dll_flags%
rem call cl flare_windows_dll_xinput.c /Fe:flare_xinput.dll %dll_flags%
rem call cl flare_windows_dll_xaudio.c /Fe:flare_xaudio.dll %dll_flags%
rem call cl flare_windows_dll_d3d11.cpp /Fe:flare_d3d11.dll %dll_flags%
rem call cl flare_windows_dll_d3d12.cpp /Fe:flare_d3d12.dll %dll_flags%
call cl %target_files% /Fe:%exe_filename% %exe_flags%
exit /b %errorlevel%

:label_build_clang
set base_flags=-Wall -nostdlib -nostdlib++ -D FLARE_COMPILER_CLANG
set link_flags=-fuse-ld=lld -Wl,-subsystem:windows
if /i "%1" equ "release" (
	set base_flags=%base_flags% -O3
) else (
	set base_flags=%base_flags% -g -gcodeview
)
rem set dll_flags=
set exe_flags=%base_flags% %link_flags%
call clang %target_files% -o %exe_filename% %compiler_flags% %files_to_compile% %linker_flags%
exit /b %errorlevel%

rem call gcc

rem :label_usage
rem echo Usage: build [COMPILER] [MODE]
rem echo COMPILER: can either be MSVC, CLANG, or GCC (case-insensitive)
rem echo MODE: can either be DEBUG, or RELEASE (case-insensitive)
rem echo.
