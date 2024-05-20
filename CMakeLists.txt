cmake_minimum_required(VERSION 2.9)
project(urisc CXX)

# Set compiler parameters
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ansi -s -Wall -Wextra -Wpedantic")

# Sources
file(GLOB SRC_FILES src/*.cpp src/*.hpp)

# Compile the main executable
add_executable(${CMAKE_PROJECT_NAME} ${SRC_FILES})

# Define the files location during install process
install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION "bin")

# Define the 'run' target
add_custom_target(run
    COMMAND ${CMAKE_PROJECT_NAME}
    DEPENDS ${CMAKE_PROJECT_NAME}
    WORKING_DIRECTORY ../${CMAKE_PROJECT_DIR}
)
