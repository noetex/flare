@echo off

if /i "%1" equ "clean" (
	del /q .\build\*.*>nul
	exit /b 0
)

if not exist build mkdir build

set target_files=src/flare.c
set exe_filename=build\flare.exe
set res_filename=build\flare.res
set map_filename=build\flare.map
set obj_filename=build\garbage.obj
set pdb_filename=build\garbage.pdb

set base_flags=/nologo /W3 /Oi /D FLARE_SYSTEM_WINDOWS /D FLARE_COMPILER_MSVC /Zi /MT /D FLARE_BUILD_DEBUG
set link_flags=/WX /incremental:no /opt:ref,icf /ignore:4099

set exe_flags=%base_flags% /Fe:%exe_filename% /Fo:%obj_filename% /Fd:%pdb_filename% /Fm:%map_filename%
call rc /nologo /fo %res_filename% src/flare.rc
call cl %target_files% %exe_flags% /link %link_flags% /subsystem:windows %res_filename%
