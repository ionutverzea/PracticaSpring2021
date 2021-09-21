@ECHO OFF
SET "BuildFolder=C:\Users\Laur\source\repos\Practica Siemens\Project\build"
ECHO Folderul de Build este: %BuildFolder%
SET "App=%BuildFolder%\bin\x64\Debug\App.exe"
ECHO Pathul catre executabil este: %App%
START "OpenApp_Batch" "%App%"