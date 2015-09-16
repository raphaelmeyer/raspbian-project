
add_library(application
  application.cc
  )
add_library(app::application ALIAS application)

target_include_directories(application
  PUBLIC include
  )

