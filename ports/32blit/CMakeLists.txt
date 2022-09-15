cmake_minimum_required(VERSION 3.12)

# Set build type to reduce firmware size
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE MinSizeRel)
endif()

# Set main target and component locations
set(MICROPY_TARGET 32blit-micropython)
get_filename_component(MICROPY_DIR "../.." ABSOLUTE)

# Set the location of this port's directory.
set(MICROPY_PORT_DIR ${CMAKE_SOURCE_DIR})

# Include component cmake fragments
include(${MICROPY_DIR}/py/py.cmake)
include(${MICROPY_DIR}/extmod/extmod.cmake)

# Define the top-level project
project(${MICROPY_TARGET})

include(${MICROPY_DIR}/py/usermod.cmake)

find_package(32BLIT CONFIG REQUIRED PATHS ../../../32blit-sdk)

set(MICROPY_SOURCE_LIB
    ${MICROPY_DIR}/shared/readline/readline.c
    ${MICROPY_DIR}/shared/runtime/gchelper_generic.c
    ${MICROPY_DIR}/shared/runtime/pyexec.c
    ${MICROPY_DIR}/shared/runtime/stdout_helpers.c
)

set(MICROPY_SOURCE_PORT
    main.cpp
    mphalport.cpp
    mod32blit.c
    mod32blit.cpp
    blit-helpers.cpp
    vfs-blit.c
    vfs-blit.cpp

    api/buttonstate.c
    api/buttonstate.cpp
    api/enums.c
    api/font.c
    api/font.cpp
    api/point.c
    api/point.cpp
    api/rect.c
    api/rect.cpp
    api/size.c
    api/size.cpp
    api/surface.c
    api/surface.cpp
    api/vec2.c
    api/vec2.cpp
)

set(MICROPY_SOURCE_QSTR
    ${MICROPY_SOURCE_PY}
    ${MICROPY_SOURCE_EXTMOD}
    ${PROJECT_SOURCE_DIR}/mod32blit.c
    ${PROJECT_SOURCE_DIR}/vfs-blit.c
    ${PROJECT_SOURCE_DIR}/api/buttonstate.c
    ${PROJECT_SOURCE_DIR}/api/enums.c
    ${PROJECT_SOURCE_DIR}/api/font.c
    ${PROJECT_SOURCE_DIR}/api/point.c
    ${PROJECT_SOURCE_DIR}/api/rect.c
    ${PROJECT_SOURCE_DIR}/api/size.c
    ${PROJECT_SOURCE_DIR}/api/surface.c
    ${PROJECT_SOURCE_DIR}/api/surface.cpp
    ${PROJECT_SOURCE_DIR}/api/vec2.c
)

blit_executable(${MICROPY_TARGET}
    ${MICROPY_SOURCE_PY}
    ${MICROPY_SOURCE_EXTMOD}
    ${MICROPY_SOURCE_LIB}
    ${MICROPY_SOURCE_PORT}
)

blit_metadata(${MICROPY_TARGET} metadata.yml)

target_link_libraries(${MICROPY_TARGET} usermod m)

target_include_directories(${MICROPY_TARGET} PRIVATE
    ${MICROPY_INC_CORE}
    ${MICROPY_INC_USERMOD}
    ${MICROPY_BOARD_DIR}
    "${PROJECT_SOURCE_DIR}"
    "${CMAKE_BINARY_DIR}"
)

target_compile_options(${MICROPY_TARGET} PRIVATE
    -Wall
    -Werror
)

target_compile_definitions(${MICROPY_TARGET} PRIVATE
    MICROPY_BUILD_TYPE="${CMAKE_C_COMPILER_ID} ${CMAKE_C_COMPILER_VERSION} ${CMAKE_BUILD_TYPE}"
)

# Include the main MicroPython cmake rules.
include(${MICROPY_DIR}/py/mkrules.cmake)
