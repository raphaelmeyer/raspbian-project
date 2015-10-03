cmake_minimum_required(VERSION 3.0.0)

project(display VERSION 0.0.1)

add_definitions(
  -std=c++11
  -Wall
  -Werror
  )

add_subdirectory(main)
add_subdirectory(application)
add_subdirectory(unit-tests)
add_subdirectory(integration-tests)
add_subdirectory(gmock-1.7.0)

