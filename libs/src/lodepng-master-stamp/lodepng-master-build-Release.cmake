

set(command "${make}")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "/home/fabio/workspace/obj-viewer/libs/src/lodepng-master-stamp/lodepng-master-build-out.log"
  ERROR_FILE "/home/fabio/workspace/obj-viewer/libs/src/lodepng-master-stamp/lodepng-master-build-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  /home/fabio/workspace/obj-viewer/libs/src/lodepng-master-stamp/lodepng-master-build-*.log")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "lodepng-master build command succeeded.  See also /home/fabio/workspace/obj-viewer/libs/src/lodepng-master-stamp/lodepng-master-build-*.log")
  message(STATUS "${msg}")
endif()
