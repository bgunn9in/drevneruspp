cmake_minimum_required(VERSION 3.20)

project(DrevnerusPP VERSION 1.0.0 LANGUAGES CXX)

include(CTest)

add_library(drevneruspp INTERFACE)
target_include_directories(
    drevneruspp
    INTERFACE
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
target_compile_features(drevneruspp INTERFACE cxx_std_17)

function(add_drevnerus_example target source)
    add_executable(${target} ${source})
    target_link_libraries(${target} PRIVATE drevneruspp)

    if(MSVC)
        target_compile_options(
            ${target}
            PRIVATE
                /utf-8
                /W4
                /EHsc
                /permissive-
                /Zc:preprocessor
        )
    else()
        target_compile_options(${target} PRIVATE -Wall -Wextra -Wpedantic)
    endif()

    if(BUILD_TESTING)
        add_test(NAME ${target} COMMAND ${target})
    endif()
endfunction()

add_drevnerus_example(bogatyrs   examples/01_bogatyrs.cpp)
add_drevnerus_example(koshchei   examples/02_koshchei.cpp)
add_drevnerus_example(marusya    examples/03_marusya.cpp)
add_drevnerus_example(potions    examples/04_potions.cpp)
add_drevnerus_example(bugtracker examples/05_bugtracker.cpp)
add_drevnerus_example(turnip     examples/06_turnip.cpp)

