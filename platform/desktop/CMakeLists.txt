find_package(SDL3 REQUIRED)

add_executable(gbaemu main.cpp)

target_link_libraries(gbaemu gbacore SDL3::SDL3)

