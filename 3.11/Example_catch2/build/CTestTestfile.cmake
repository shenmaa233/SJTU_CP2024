# CMake generated Testfile for 
# Source directory: /home/shenmaa/CP2024_code/3.11/Example_catch2
# Build directory: /home/shenmaa/CP2024_code/3.11/Example_catch2/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(UnitTests "UnitTests_catch2")
set_tests_properties(UnitTests PROPERTIES  _BACKTRACE_TRIPLES "/home/shenmaa/CP2024_code/3.11/Example_catch2/CMakeLists.txt;21;add_test;/home/shenmaa/CP2024_code/3.11/Example_catch2/CMakeLists.txt;0;")
subdirs("_deps/catch2-build")
