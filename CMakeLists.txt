cmake_minimum_required(VERSION 3.16)

project(VehicleTelemetryEngine VERSION 0.1.0 LANGUAGES CXX)

add_executable(vte_engine
    src/main.cpp
)

target_compile_features(vte_engine PRIVATE cxx_std_17)

if(MSVC)
    target_compile_options(vte_engine PRIVATE /W4 /permissive-)
else()
    target_compile_options(vte_engine PRIVATE -Wall -Wextra -Wpedantic)
endif()

include(CTest)
if(BUILD_TESTING)
    add_test(NAME engine_smoke COMMAND vte_engine)
endif()
