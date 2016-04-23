

set(command "/opt/clion-2016.1.1/bin/cmake/bin/cmake;-GUnix Makefiles;/home/fabio/workspace/obj-viewer/libs/lodepng")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "/home/fabio/workspace/obj-viewer/libs/src/lodepng-master-stamp/lodepng-master-configure-out.log"
  ERROR_FILE "/home/fabio/workspace/obj-viewer/libs/src/lodepng-master-stamp/lodepng-master-configure-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  /home/fabio/workspace/obj-viewer/libs/src/lodepng-master-stamp/lodepng-master-configure-*.log")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "lodepng-master configure command succeeded.  See also /home/fabio/workspace/obj-viewer/libs/src/lodepng-master-stamp/lodepng-master-configure-*.log")
  message(STATUS "${msg}")
endif()
