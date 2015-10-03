project(integration-tests)

add_executable(integration-tests
  integration.cc
  display_stub.cc
  )
add_executable(test::integration-tests ALIAS integration-tests)

target_link_libraries(integration-tests
  PRIVATE test::gmock-main
  PRIVATE app::application
  )

