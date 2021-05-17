project (App)

set(OpenCV_STATIC OFF)

add_subdirectory ("include")
add_subdirectory ("src")

source_group ("Header Files" FILES ${headers})
source_group ("Source Files" FILES ${sources})

include_directories (${GraphicalProcessingDLL_IncludeDir} ${UIDLL_IncludeDir} ${OpenCV_INCLUDE_DIRS})
link_directories (${OpenCV_LIB_DIR})

add_executable (App ${sources} ${headers})

SET(OpenCV_DLL_Path "${OpenCV_DIR}/x64/vc16/bin")
# SET(PathRelease "${OpenCV_DIR}/x64/vc16/bin")
message(STATUS "    pathDebug: ${OpenCV_DLL_Path}")
message(STATUS "	pathRelease: ${OpenCV_DLL_Path}")
message("	CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")	

SET (OpenCV_DLLs_D 	${OpenCV_DLL_Path}/opencv_core452d.dll
					${OpenCV_DLL_Path}/opencv_highgui452d.dll
					${OpenCV_DLL_Path}/opencv_imgcodecs452d.dll
					${OpenCV_DLL_Path}/opencv_imgproc452d.dll
					${OpenCV_DLL_Path}/opencv_videoio452d.dll	)

SET (OpenCV_DLLs_R 	${OpenCV_DLL_Path}/opencv_core452.dll
					${OpenCV_DLL_Path}/opencv_highgui452.dll
					${OpenCV_DLL_Path}/opencv_imgcodecs452.dll
					${OpenCV_DLL_Path}/opencv_imgproc452.dll
					${OpenCV_DLL_Path}/opencv_videoio452.dll	)
				
install (FILES ${OpenCV_DLLs_D} DESTINATION ${CMAKE_BINARY_DIR}/build/bin/X64/Debug CONFIGURATIONS Debug)
install (FILES ${OpenCV_DLLs_R} DESTINATION ${CMAKE_BINARY_DIR}/build/bin/X64/Release CONFIGURATIONS Release)

target_link_libraries (App GraphicalProcessingDLL UIDLL ${OpenCV_LIBS})