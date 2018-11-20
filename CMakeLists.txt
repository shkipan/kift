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
        ${PROJECT_SOURCE_DIR}/server/
        ${PROJECT_SOURCE_DIR}/client/
        ${PROJECT_SOURCE_DIR}/client/runer/
        ${PROJECT_SOURCE_DIR}/lib/SmartString/
        ${PROJECT_SOURCE_DIR}/lib/Sphinx/
        ${PROJECT_SOURCE_DIR}/lib/Sphinx/include/
        ${PROJECT_SOURCE_DIR}/lib/Sphinx/include/pocketsphinx
        ${PROJECT_SOURCE_DIR}/lib/Sphinx/include/sphinxbase
)


add_executable(server server/main.c server/server.c server/server.h)

add_executable(client client/main.c
        client/runer/runer.c
        client/runer/functions.c
        client/client.c)

target_link_libraries(server
        "${PROJECT_SOURCE_DIR}/lib/Sphinx/lib/libpocketsphinx.a"
        "${PROJECT_SOURCE_DIR}/lib/Sphinx/lib/libsphinxbase.a"
        "${PROJECT_SOURCE_DIR}/libft/libft.a")

target_link_libraries(client
        "${PROJECT_SOURCE_DIR}/lib/Sphinx/lib/libpocketsphinx.a"
        "${PROJECT_SOURCE_DIR}/lib/Sphinx/lib/libsphinxbase.a"
        "${PROJECT_SOURCE_DIR}/libft/libft.a")
