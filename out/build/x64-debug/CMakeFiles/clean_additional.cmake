# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\MP3Lint_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\MP3Lint_autogen.dir\\ParseCache.txt"
  "MP3Lint_autogen"
  "_deps\\taglib-build\\taglib\\CMakeFiles\\tag_autogen.dir\\AutogenUsed.txt"
  "_deps\\taglib-build\\taglib\\CMakeFiles\\tag_autogen.dir\\ParseCache.txt"
  "_deps\\taglib-build\\taglib\\tag_autogen"
  )
endif()
