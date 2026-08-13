if (NOT EXISTS "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-build/install_manifest.txt")
  message(FATAL_ERROR "Cannot find install manifest: \"C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-build/install_manifest.txt\"")
endif()

file(READ "C:/Users/Joefi/source/repos/MP3Lint/out/build/x64-debug/_deps/taglib-build/install_manifest.txt" files)
string(REGEX REPLACE "\n" ";" files "${files}")
foreach (file ${files})
  message(STATUS "Uninstalling \"$ENV{DESTDIR}${file}\"")
  if (EXISTS "$ENV{DESTDIR}${file}")
    execute_process(
      COMMAND C:/Program Files/Microsoft Visual Studio/18/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe -E remove "$ENV{DESTDIR}${file}"
      OUTPUT_VARIABLE rm_out
      RESULT_VARIABLE rm_retval
    )
    if(NOT ${rm_retval} EQUAL 0)
      message(FATAL_ERROR "Problem when removing \"$ENV{DESTDIR}${file}\"")
    endif ()
  else ()
    message(STATUS "File \"$ENV{DESTDIR}${file}\" does not exist.")
  endif ()
endforeach()
