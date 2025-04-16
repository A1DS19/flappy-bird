# Enable export of compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Specify minimum CMake version
cmake_minimum_required(VERSION 3.31.6)

# Set the project name dynamically based on the folder name
get_filename_component(PROJECT_NAME ${CMAKE_SOURCE_DIR} NAME)
project(${PROJECT_NAME})

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Compiler flags (e.g., debug information)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

# Source files (all .cpp files in the src directory)
file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)

# Add executable
add_executable(main ${SOURCES})

# Set the output directory for the executable
set_target_properties(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# See what is happening during linking
set(CMAKE_VERBOSE_MAKEFILE ON)

# Add library directory
link_directories(${CMAKE_SOURCE_DIR}/lib)

# Link pdcurses library
# target_link_libraries(main PRIVATE pdcurses) uncomment and add library

include(FetchContent)

set(BUILD_SHARED_LIBS        OFF  CACHE BOOL "" FORCE)  
set(SFML_BUILD_EXAMPLES      OFF  CACHE BOOL "" FORCE)
set(SFML_BUILD_TEST_SUITE    OFF  CACHE BOOL "" FORCE)
set(SFML_BUILD_DOC           OFF  CACHE BOOL "" FORCE)

FetchContent_Declare(
  sfml
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG        3.0.0
)

FetchContent_MakeAvailable(sfml)  

target_link_libraries(
    main
    PRIVATE
        sfml-graphics
        sfml-window
        sfml-system
)

# Warnings into errors
# target_compile_options(main PRIVATE -Wall -Wextra -Werror)

# Custom target to generate .clang_complete (optional)
add_custom_target(
  generate_clang_complete
  COMMAND python ${CMAKE_SOURCE_DIR}/scripts/cc_args.py ${CMAKE_BINARY_DIR}/compile_commands.json > ${CMAKE_SOURCE_DIR}/.clang_complete
  DEPENDS ${CMAKE_BINARY_DIR}/compile_commands.json
)
