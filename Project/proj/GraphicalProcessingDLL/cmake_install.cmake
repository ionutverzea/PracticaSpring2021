# Install script for directory: D:/PB_SIEMENS/Procesare_img/Project/GraphicalProcessingDLL

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files/Application")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "D:/PB_SIEMENS/Procesare_img/Project/proj/build/bin/X64/Debug/opencv_core452d.dll;D:/PB_SIEMENS/Procesare_img/Project/proj/build/bin/X64/Debug/opencv_highgui452d.dll;D:/PB_SIEMENS/Procesare_img/Project/proj/build/bin/X64/Debug/opencv_imgcodecs452d.dll;D:/PB_SIEMENS/Procesare_img/Project/proj/build/bin/X64/Debug/opencv_imgproc452d.dll;D:/PB_SIEMENS/Procesare_img/Project/proj/build/bin/X64/Debug/opencv_videoio452d.dll")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
        message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
        message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
file(INSTALL DESTINATION "D:/PB_SIEMENS/Procesare_img/Project/proj/build/bin/X64/Debug" TYPE FILE FILES
      "D:/PB_SIEMENS/Procesare_img/Dependencies/OpenCV_4.2.0_build/x64/vc16/bin/opencv_core452d.dll"
      "D:/PB_SIEMENS/Procesare_img/Dependencies/OpenCV_4.2.0_build/x64/vc16/bin/opencv_highgui452d.dll"
      "D:/PB_SIEMENS/Procesare_img/Dependencies/OpenCV_4.2.0_build/x64/vc16/bin/opencv_imgcodecs452d.dll"
      "D:/PB_SIEMENS/Procesare_img/Dependencies/OpenCV_4.2.0_build/x64/vc16/bin/opencv_imgproc452d.dll"
      "D:/PB_SIEMENS/Procesare_img/Dependencies/OpenCV_4.2.0_build/x64/vc16/bin/opencv_videoio452d.dll"
      )
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "D:/PB_SIEMENS/Procesare_img/Project/proj/build/bin/X64/Release/opencv_core452.dll;D:/PB_SIEMENS/Procesare_img/Project/proj/build/bin/X64/Release/opencv_highgui452.dll;D:/PB_SIEMENS/Procesare_img/Project/proj/build/bin/X64/Release/opencv_imgcodecs452.dll;D:/PB_SIEMENS/Procesare_img/Project/proj/build/bin/X64/Release/opencv_imgproc452.dll;D:/PB_SIEMENS/Procesare_img/Project/proj/build/bin/X64/Release/opencv_videoio452.dll")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
        message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
        message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
file(INSTALL DESTINATION "D:/PB_SIEMENS/Procesare_img/Project/proj/build/bin/X64/Release" TYPE FILE FILES
      "D:/PB_SIEMENS/Procesare_img/Dependencies/OpenCV_4.2.0_build/x64/vc16/bin/opencv_core452.dll"
      "D:/PB_SIEMENS/Procesare_img/Dependencies/OpenCV_4.2.0_build/x64/vc16/bin/opencv_highgui452.dll"
      "D:/PB_SIEMENS/Procesare_img/Dependencies/OpenCV_4.2.0_build/x64/vc16/bin/opencv_imgcodecs452.dll"
      "D:/PB_SIEMENS/Procesare_img/Dependencies/OpenCV_4.2.0_build/x64/vc16/bin/opencv_imgproc452.dll"
      "D:/PB_SIEMENS/Procesare_img/Dependencies/OpenCV_4.2.0_build/x64/vc16/bin/opencv_videoio452.dll"
      )
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("D:/PB_SIEMENS/Procesare_img/Project/proj/GraphicalProcessingDLL/src/cmake_install.cmake")
  include("D:/PB_SIEMENS/Procesare_img/Project/proj/GraphicalProcessingDLL/include/cmake_install.cmake")

endif()

