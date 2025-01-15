cmake_minimum_required(VERSION 3.15)

project(SpaceProject VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(SpaceProject space_project/Source.cpp)

# find SFML package
find_package(SFML 2.5.1 REQUIRED COMPONENTS graphics window system)

# include directories
target_include_directories(SpaceProject PRIVATE 
    ${SFML_INCLUDE_DIR}
    include
)

# link SFML libraries
target_link_libraries(SpaceProject PRIVATE 
    sfml-system
    sfml-window
    sfml-graphics
)

# set output directories for clarity
set_target_properties(SpaceProject PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

# print project info
message(STATUS "Project: ${PROJECT_NAME}")
message(STATUS "Version: ${PROJECT_VERSION}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")

# copy assets folder to the build directory
file(COPY ${CMAKE_SOURCE_DIR}/space_project/assets DESTINATION ${CMAKE_BINARY_DIR}/assets)

