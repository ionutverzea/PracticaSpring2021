#pragma once

#ifdef UI_LIB_as_DLL
#define UILIBRARY_API __declspec(dllexport)
#else
#define UILIBRARY_API __declspec(dllimport)
#endif

extern "C" UILIBRARY_API void UILibraryTest();