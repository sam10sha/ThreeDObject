@echo off

if [%1] == [main] (
    call:bin\Main.exe
) else if [%1] == [clean] (
    call:clean
) else (
    call:error
)
goto done



::Outputs
:bin\Main.exe
set obj_dependency_list=obj\driver.obj
call:Main_exe_objs
call:bin
if not exist bin\Main.exe (
    link /out:bin\Main.exe %obj_dependency_list%
)
set obj_dependency_list=
goto:eof
:Main_exe_objs
set src_dependency_list=src\Sources\driver.cpp
call:obj
for %%i in (%src_dependency_list%) do (
    if not exist obj\%%~ni.obj (
        cl /c /EHsc /I"%cd%\src\Headers" %%i /Foobj\%%~ni.obj
    )
)
set src_dependency_list=
goto:eof

::Directories
:bin
if not exist bin (
    md bin
)
goto:eof

:lib
if not exist lib (
    md lib
)
goto:eof

:obj
if not exist obj (
    md obj
)
goto:eof


::Utilities
:clean
set del_list=bin lib obj
for %%i in (%del_list%) do (
    if exist %%i (
        del /q %%i\*
    )
)
set del_list=
goto:eof

:error
echo Invalid arguments
goto:eof


:done
