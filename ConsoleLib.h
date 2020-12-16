/* ------------------------------------------------ */
/* ------------------CONSOLE LIB------------------- */
/* ------------------------------------------------ */
/* A Blitz3D library for opening and outputting to  */
/*					a cmd window.					*/
/* <<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>> */

#include <string>
#include <stdlib.h>
#include <Windows.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <iostream>
#include <fstream>
#include <cstdlib>

#define CMDLIB(x) extern "C" __declspec(dllexport) x _stdcall

//*VARIABLES***************
HWND	console;
HWND	b3d;
HANDLE	stdhandle;
HANDLE	out;
//*************************

CMDLIB(void) CreateConsole		(const char* consoleTitle, const char* window, int hideWindow);
CMDLIB(void) ConsoleLog			(const char* message, int color);
CMDLIB(void) ConsoleTitle		(const char* title);
CMDLIB(void) BringGraphicsBack	();