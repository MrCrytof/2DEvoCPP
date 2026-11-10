cmake_minimum_required(VERSION 3.20)

project(2D_Evo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(RAYLIB_PATH "C:/raylib-6.2_win64_mingw-w64")

add_executable(2D_Evo
        main.cpp
        render.cpp
)

target_include_directories(2D_Evo PRIVATE
        "${RAYLIB_PATH}/include"
)

target_link_libraries(2D_Evo PRIVATE
        "${RAYLIB_PATH}/lib/libraylib.a"
        opengl32
        gdi32
        winmm
)