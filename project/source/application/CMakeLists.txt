
add_library(application
  application.cc
  )
add_library(app::application ALIAS application)

target_include_directories(application
  PUBLIC include
  )

set_property(TARGET application PROPERTY CXX_STANDARD 14)
set_property(TARGET application PROPERTY CXX_STANDARD_REQUIRED ON)

