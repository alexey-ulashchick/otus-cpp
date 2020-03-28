add_library(
  greetings
  greetings.h
  greetings.cpp
  )

target_include_directories(greetings PUBLIC "${CMAKE_CURRENT_SOURCE_DIRECTORY}")
