# CMakeList.txt : CMake project for SnakeEditor, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("SnakeEditor")

# Add source to this project's executable.
add_executable (SnakeEditor "SnakeEditor.cpp" "SnakeEditor.h")


include_directories(SnakeEditor "C:/Users/adhir/Downloads/libs/SFML-2.5.1-windows-vc15-64-bit/SFML-2.5.1/include")

target_link_libraries(SnakeEditor LINK_PUBLIC "C:/Users/adhir/Downloads/libs/SFML-2.5.1-windows-vc15-64-bit/SFML-2.5.1/lib/sfml-main-d.lib")
target_link_libraries(SnakeEditor LINK_PUBLIC "C:/Users/adhir/Downloads/libs/SFML-2.5.1-windows-vc15-64-bit/SFML-2.5.1/lib/sfml-system-d.lib")
target_link_libraries(SnakeEditor LINK_PUBLIC "C:/Users/adhir/Downloads/libs/SFML-2.5.1-windows-vc15-64-bit/SFML-2.5.1/lib/sfml-window-d.lib")
target_link_libraries(SnakeEditor LINK_PUBLIC "C:/Users/adhir/Downloads/libs/SFML-2.5.1-windows-vc15-64-bit/SFML-2.5.1/lib/sfml-graphics-d.lib")

# TODO: Add tests and install targets if needed.
