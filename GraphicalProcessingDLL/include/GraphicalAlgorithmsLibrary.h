#pragma once

#ifdef G_LIB_as_DLL
#define GRAPHICALLIBRARY_API __declspec(dllexport)
#else
#define GRAPHICALLIBRARY_API __declspec(dllimport)
#endif

extern "C" GRAPHICALLIBRARY_API void GraphLibraryTest();