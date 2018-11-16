cmake_minimum_required(VERSION 3.9)
project(kift C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")
include_directories(
        ${PROJECT_SOURCE_DIR}/
        ${PROJECT_SOURCE_DIR}/webserver/
        ${PROJECT_SOURCE_DIR}/libft/
        ${PROJECT_SOURCE_DIR}/libft/includes/
        ${PROJECT_SOURCE_DIR}/lib/
        client/runer/
        ${PROJECT_SOURCE_DIR}/lib/SmartString/
        ${PROJECT_SOURCE_DIR}/lib/SphinxBase/
        ${PROJECT_SOURCE_DIR}/lib/SphinxBase/bin/
        ${PROJECT_SOURCE_DIR}/lib/SphinxBase/include/
        ${PROJECT_SOURCE_DIR}/lib/SphinxBase/include/sphinxbase/
        ${PROJECT_SOURCE_DIR}/lib/SphinxBase/lib/
        ${PROJECT_SOURCE_DIR}/lib/PocketSphinx/
        ${PROJECT_SOURCE_DIR}/lib/PocketSphinx/bin/
        ${PROJECT_SOURCE_DIR}/lib/PocketSphinx/include/
        ${PROJECT_SOURCE_DIR}/lib/PocketSphinx/include/pocketsphinx/
        ${PROJECT_SOURCE_DIR}/lib/PocketSphinx/lib/)

add_executable(kift main.c webserver/server.c client/runer/runer.c
        client/runer/functions.c)


target_link_libraries(kift
        "${PROJECT_SOURCE_DIR}/lib/PocketSphinx/lib/libpocketsphinx.a"
        "${PROJECT_SOURCE_DIR}/lib/SphinxBase/lib/libsphinxbase.a"
        "${PROJECT_SOURCE_DIR}/libft/libft.a")
