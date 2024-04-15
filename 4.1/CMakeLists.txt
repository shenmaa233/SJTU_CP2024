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

#调python包
find_package(PythonLibs REQUIRED)
include_directories(/home/shenmaa/.local/lib/python3.10/site-packages/numpy/core/include)

# Project executable
add_executable(main Ising_model.cpp IsingSpin.cpp IsingSpinOnLattice.cpp IsingSystem.cpp IsingSystem_Square.cpp IsingSystem_Honey.cpp)
target_compile_options(main PRIVATE -Wall -Wextra)

# 包含Python头文件路径
include_directories(${PYTHON_INCLUDE_DIRS})
target_include_directories(main PRIVATE ${PYTHON_INCLUDE_DIRS})

# 链接Python库
target_link_libraries(main ${PYTHON_LIBRARIES})

#plottest测试
add_executable(plottest matplotlibtest.cpp)
target_compile_options(plottest PRIVATE -Wall -Wextra)
include_directories(${PYTHON_INCLUDE_DIRS})
target_include_directories(plottest PRIVATE ${PYTHON_INCLUDE_DIRS})
target_link_libraries(plottest ${PYTHON_LIBRARIES})

# Test executable
enable_testing()
add_executable(Tests_IsingSpin Test_IsingSpin.cpp IsingSpin.cpp IsingSpinOnLattice.cpp IsingSystem.cpp IsingSystem_Square.cpp)
target_compile_options(Tests_IsingSpin PRIVATE -Wall -Wextra)
target_link_libraries(Tests_IsingSpin Catch2::Catch2WithMain)
add_test(NAME Tests COMMAND Tests_IsingSpin)
