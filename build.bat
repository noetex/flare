@echo off

if /i "%1" equ "clean" (
	del /q .\build\*.*>nul
	exit /b 0
)

if not exist build mkdir build

set target_files=src/flare.c
set lib_files=kernel32.lib user32.lib pathcch.lib gdi32.lib opengl32.lib "3rd_party\glew-2.2.0\lib\Release\x64\glew32s.lib"
set exe_filename=build\flare.exe
set obj_filename=build\flare.obj
set res_filename=build\flare.res
set pdb_filename=build\garbage.pdb

if /i "%1" equ "release" goto label_build_clang

:label_build_msvc
set base_flags=/nologo /W3 /D FLARE_SYSTEM_WINDOWS /D FLARE_COMPILER_MSVC /Zi /D FLARE_BUILD_DEBUG
set link_flags=/WX /incremental:no /opt:ref,icf /ignore:4099

set exe_flags=%base_flags% /Fe:%exe_filename% /Fo:%obj_filename% /Fd:%pdb_filename%
call rc /nologo /fo %res_filename% src/flare.rc
call cl %target_files% %exe_flags% /link %link_flags% /subsystem:windows %lib_files% %res_filename%
exit /b %errorlevel%


:label_build_clang
set base_flags=-O3 -Wall -D FLARE_SYSTEM_WINDOWS -D FLARE_COMPILER_CLANG
set link_flags=-fuse-ld=lld -Wl,-subsystem:windows
set exe_flags=%base_flags% -o %exe_filename% %link_flags%
call clang %target_files% %exe_flags% %lib_files%
exit /b %errorlevel%
