cmake_minimum_required(VERSION 3.14)
project(Test_of_Catch2 CXX)
set(CMAKE_CXX_STANDARD 14)

# Fetch Catch2 from GitHub
include(FetchContent)
FetchContent_Declare(catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.0.1 
)
FetchContent_MakeAvailable(catch2)

# Project executable
add_executable(main Ising_model.cpp IsingSpin.cpp IsingSpinOnLattice.cpp IsingSystem.cpp IsingSystem_Square.cpp)
target_compile_options(main PRIVATE -Wall -Wextra)

# Test executable
enable_testing()
add_executable(Tests_IsingSpin Test_IsingSpin.cpp IsingSpin.cpp IsingSpinOnLattice.cpp IsingSystem.cpp IsingSystem_Square.cpp)
target_compile_options(Tests_IsingSpin PRIVATE -Wall -Wextra)
target_link_libraries(Tests_IsingSpin Catch2::Catch2WithMain)
add_test(NAME Tests COMMAND Tests_IsingSpin)
