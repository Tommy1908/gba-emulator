file (GLOB_RECURSE core_headers CONFIGURE_DEPENDS "include/*.h")

file (GLOB_RECURSE core_sources CONFIGURE_DEPENDS "src/*.cpp")

add_library(gbacore STATIC ${core_headers} ${core_sources})

target_include_directories(gbacore PUBLIC include)

