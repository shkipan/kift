cmake_minimum_required(VERSION 3.9)
project(kift C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")
include_directories(
        ${PROJECT_SOURCE_DIR}/
        ${PROJECT_SOURCE_DIR}/webInterface/
        ${PROJECT_SOURCE_DIR}/libft/
        ${PROJECT_SOURCE_DIR}/libft/includes/
        ${PROJECT_SOURCE_DIR}/lib/
        ${PROJECT_SOURCE_DIR}/client/runer/
        ${PROJECT_SOURCE_DIR}/lib/SmartString/
        ${PROJECT_SOURCE_DIR}/lib/Sphinx/
        ${PROJECT_SOURCE_DIR}/lib/Sphinx/include/
        ${PROJECT_SOURCE_DIR}/lib/Sphinx/include/pocketsphinx
        ${PROJECT_SOURCE_DIR}/lib/Sphinx/include/sphinxbase
)

add_executable(kift main.c client/runer/runer.c
        client/runer/functions.c
        webInterface/server.c)


target_link_libraries(kift
        "${PROJECT_SOURCE_DIR}/lib/Sphinx/lib/libpocketsphinx.a"
        "${PROJECT_SOURCE_DIR}/lib/Sphinx/lib/libsphinxbase.a"
        "${PROJECT_SOURCE_DIR}/libft/libft.a")
