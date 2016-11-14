

enable_testing()

# Make sure that we're compiling C++14 source code.
set(CMAKE_CXX_FLAGS "-std=c++11")

add_executable(test-HashChain HashChain.cpp)
add_executable(test-HashOpen HashOpen.cpp)
add_executable(test-ChainFind ChainTestFind.cpp)
add_executable(test-OpenFind OpenTestFind.cpp)
add_executable(test-ChainInsert ChainTestInsert.cpp)
add_executable(test-OpenInsert OpenTestInsert.cpp)
#add_executable(test-vector-binary vector-binary.cpp)
#add_executable(test-vector-sort vector-sort.cpp)
macro(add_printout)
  add_custom_target(printout
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMAND a2ps -Afill -o- ${ARGN} | ps2pdf - ${CMAKE_BINARY_DIR}/printout.pdf)
endmacro()


# Add files to the output.
#add_printout(AVLtree.hpp AVLtree.cpp tree.hpp tree.cpp benchmark.cpp AVLbenchmark.cpp)
