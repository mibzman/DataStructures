

enable_testing()

# Make sure that we're compiling C++14 source code.
set(CMAKE_CXX_FLAGS "-std=c++11")

add_executable(test-Graph Graph.cpp)
#add_executable(test-vector-binary vector-binary.cpp)
#add_executable(test-vector-sort vector-sort.cpp)
macro(add_printout)
  add_custom_target(printout
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMAND a2ps -Afill -o- ${ARGN} | ps2pdf - ${CMAKE_BINARY_DIR}/printout.pdf)
endmacro()


# Add files to the output.
#add_printout(AVLtree.hpp AVLtree.cpp tree.hpp tree.cpp benchmark.cpp AVLbenchmark.cpp)
