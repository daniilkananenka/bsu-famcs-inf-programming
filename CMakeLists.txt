cmake_minimum_required(VERSION 3.22)

project(cpp)

function(add_project name)
  if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${name})
    add_subdirectory(${name})
  endif()
endfunction()

add_project(lab-4/task-1)
add_project(lab-4/task-2)
add_project(lab-4/task-4)
add_project(array)
