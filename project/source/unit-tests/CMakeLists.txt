project(unit-tests)

add_executable(unit-tests
  display.cc
  dogm163.cc
  )
add_executable(test::unit-tests ALIAS unit-tests)

target_link_libraries(unit-tests
  PRIVATE test::gmock-main
  PRIVATE app::application
  )

