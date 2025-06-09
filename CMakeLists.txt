cmake_minimum_required(VERSION 3.17)
project(fsoft2025_1DC_4)

set(CMAKE_CXX_STANDARD 17)


set(PROJECT_HEADERS ${PROJECT_SOURCE_DIR}/Project/headers)
set(PROJECT_SOURCES ${PROJECT_SOURCE_DIR}/Project/sources)

function(include_all_directories_from_path RECEIVED_DIR)
    file(GLOB TEMP_DIRECTORIES "${RECEIVED_DIR}/*" DIRECTORY)
    list(FILTER TEMP_DIRECTORIES EXCLUDE REGEX ".*\\..*")
    foreach(CURRENT_DIRECTORY ${TEMP_DIRECTORIES})
        if(IS_DIRECTORY ${CURRENT_DIRECTORY})
            include_directories(${CURRENT_DIRECTORY})
        endif()
    endforeach()
endfunction()

include_all_directories_from_path(${PROJECT_HEADERS})
include_all_directories_from_path(${PROJECT_SOURCES})


file(GLOB_RECURSE PROGRAM_FILES "${PROJECT_SOURCES}/**/*" "${PROJECT_HEADERS}/**/*")

set(SOURCE_FILES
        main.cpp
        ${PROGRAM_FILES})

add_executable(fsoft2025_1DC_4 ${SOURCE_FILES})

