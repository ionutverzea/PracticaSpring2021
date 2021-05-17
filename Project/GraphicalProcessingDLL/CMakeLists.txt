project (GraphicalProcessingDLL)

set (GraphicalProcessingDLL_IncludeDir "${CMAKE_CURRENT_SOURCE_DIR}/include" CACHE INTERNAL "")

add_subdirectory("src")
add_subdirectory("include")

source_group ("Header Files" FILES ${headers})
source_group ("Source Files" FILES ${sources})

include_directories (${GraphicalProcessingDLL_IncludeDir})

add_library (GraphicalProcessingDLL SHARED ${headers} ${sources})

add_definitions (-DG_LIB_as_DLL)