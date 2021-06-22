project (UIDLL)

set (UIDLL_IncludeDir "${CMAKE_CURRENT_SOURCE_DIR}/include" CACHE INTERNAL "")

add_subdirectory("src")
add_subdirectory("include")

source_group ("Header Files" FILES ${headers})
source_group ("Source Files" FILES ${sources})

include_directories (${UIDLL_IncludeDir})

add_library (UIDLL SHARED ${headers} ${sources})

add_definitions (-DUI_LIB_as_DLL)