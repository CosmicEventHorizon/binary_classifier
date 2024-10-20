cmake_minimum_required(VERSION 3.10)

project(classifier LANGUAGES C)

include_directories(includes)

add_executable(classifier
    src/main.c
    includes/lodepng.c
)

target_link_libraries(classifier
    png
)