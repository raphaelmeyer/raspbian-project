
add_executable(display
  main.cc
  )
add_executable(app::display ALIAS display)

target_link_libraries(display
  PRIVATE app::application
  )

