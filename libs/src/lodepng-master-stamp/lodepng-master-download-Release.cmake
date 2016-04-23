

set(command "/opt/clion-2016.1.1/bin/cmake/bin/cmake;-Dmake=${make};-Dconfig=${config};-P;/home/fabio/workspace/obj-viewer/libs/src/lodepng-master-stamp/lodepng-master-download-Release-impl.cmake")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "/home/fabio/workspace/obj-viewer/libs/src/lodepng-master-stamp/lodepng-master-download-out.log"
  ERROR_FILE "/home/fabio/workspace/obj-viewer/libs/src/lodepng-master-stamp/lodepng-master-download-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  /home/fabio/workspace/obj-viewer/libs/src/lodepng-master-stamp/lodepng-master-download-*.log")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "lodepng-master download command succeeded.  See also /home/fabio/workspace/obj-viewer/libs/src/lodepng-master-stamp/lodepng-master-download-*.log")
  message(STATUS "${msg}")
endif()
