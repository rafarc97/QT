# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Threads_Runnable_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Threads_Runnable_autogen.dir/ParseCache.txt"
  "Threads_Runnable_autogen"
  )
endif()
