cmake_minimum_required(VERSION 3.22)

set(VECTOR_EXE main-vector.cpp)
set(STACK_EXE main-stack.cpp)
set(RING_BUFFER_EXE main-ring-buffer.cpp)

add_executable(vector ${VECTOR_EXE})
add_executable(stack ${STACK_EXE})
add_executable(ring-buffer ${RING_BUFFER_EXE})