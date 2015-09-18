
add_library(application
  application.cc
  display.cc
  dogm163.cc
  )
add_library(app::application ALIAS application)

target_include_directories(application
  PUBLIC include
  )

