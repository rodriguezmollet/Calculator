cmake_minimum_required(VERSION 3.31.0)

# Set the project name
project(Calculator VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
# Set the C++ standard as required
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Turn off non-standard extensions
set(CMAKE_CXX_EXTENSIONS OFF)

# To treat all warnings as errors for GNU or Clang compilers if we are in CONFIG:DEBUG
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options("$<$<CONFIG:DEBUG>:-Wall;-Wextra;-Weffc++;-Wconversion;-Wsign-conversion;-Werror;-Wshadow>")
endif()

# Add source files explicitly
set(SRC_DIR "${CMAKE_CURRENT_LIST_DIR}/src")
set(SOURCES
    "${SRC_DIR}/Core/Source Files/Calculator.cpp"
    "${SRC_DIR}/Core/Source Files/Operations.cpp"
    # Add more source files here as needed
)
# main executable
add_executable(main src/App/main.cpp ${SOURCES})

include(FetchContent)
# Google Test library
FetchContent_Declare(
    googletest
    # b514bdc898e2951020cbdca1304b75f5950d1f59 is the Git commit hash of the GoogleTest version
    # to use; Update the commit hash often to point to the latest version.
    # Current commit hash is for v1.15.2
    URL https://github.com/google/googletest/archive/b514bdc898e2951020cbdca1304b75f5950d1f59.zip
)
FetchContent_MakeAvailable(googletest)
# Now simply link against gtest or gtest_main as needed.
add_executable(OperationsTest src/Core/Tests/OperationsTest.cpp
                "${SRC_DIR}/Core/Source Files/Operations.cpp")
target_link_libraries(OperationsTest gtest_main)