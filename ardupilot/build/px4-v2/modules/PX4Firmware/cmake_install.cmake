# Install script for directory: /home/azzathesis/ardupilot/modules/PX4Firmware

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/azzathesis/ardupilot/build/px4-v2/modules/PX4Firmware/src/platforms/common/cmake_install.cmake")
  include("/home/azzathesis/ardupilot/build/px4-v2/modules/PX4Firmware/src/platforms/nuttx/cmake_install.cmake")
  include("/home/azzathesis/ardupilot/build/px4-v2/modules/PX4Firmware/src/platforms/nuttx/px4_layer/cmake_install.cmake")
  include("/home/azzathesis/ardupilot/build/px4-v2/modules/PX4Firmware/src/modules/param/cmake_install.cmake")
  include("/home/azzathesis/ardupilot/build/px4-v2/modules/PX4Firmware/src/drivers/device/cmake_install.cmake")
  include("/home/azzathesis/ardupilot/build/px4-v2/modules/PX4Firmware/src/drivers/stm32/cmake_install.cmake")
  include("/home/azzathesis/ardupilot/build/px4-v2/modules/PX4Firmware/src/drivers/stm32/adc/cmake_install.cmake")
  include("/home/azzathesis/ardupilot/build/px4-v2/modules/PX4Firmware/src/drivers/stm32/tone_alarm/cmake_install.cmake")
  include("/home/azzathesis/ardupilot/build/px4-v2/modules/PX4Firmware/src/drivers/led/cmake_install.cmake")
  include("/home/azzathesis/ardupilot/build/px4-v2/modules/PX4Firmware/src/drivers/px4fmu/cmake_install.cmake")
  include("/home/azzathesis/ardupilot/build/px4-v2/modules/PX4Firmware/src/systemcmds/bl_update/cmake_install.cmake")
  include("/home/azzathesis/ardupilot/build/px4-v2/modules/PX4Firmware/src/systemcmds/mixer/cmake_install.cmake")
  include("/home/azzathesis/ardupilot/build/px4-v2/modules/PX4Firmware/src/systemcmds/perf/cmake_install.cmake")
  include("/home/azzathesis/ardupilot/build/px4-v2/modules/PX4Firmware/src/systemcmds/reboot/cmake_install.cmake")
  include("/home/azzathesis/ardupilot/build/px4-v2/modules/PX4Firmware/src/systemcmds/top/cmake_install.cmake")
  include("/home/azzathesis/ardupilot/build/px4-v2/modules/PX4Firmware/src/systemcmds/nshterm/cmake_install.cmake")
  include("/home/azzathesis/ardupilot/build/px4-v2/modules/PX4Firmware/src/systemcmds/mtd/cmake_install.cmake")
  include("/home/azzathesis/ardupilot/build/px4-v2/modules/PX4Firmware/src/systemcmds/ver/cmake_install.cmake")
  include("/home/azzathesis/ardupilot/build/px4-v2/modules/PX4Firmware/src/systemcmds/usb_connected/cmake_install.cmake")
  include("/home/azzathesis/ardupilot/build/px4-v2/modules/PX4Firmware/src/systemcmds/otp/cmake_install.cmake")
  include("/home/azzathesis/ardupilot/build/px4-v2/modules/PX4Firmware/src/modules/systemlib/cmake_install.cmake")
  include("/home/azzathesis/ardupilot/build/px4-v2/modules/PX4Firmware/src/modules/systemlib/mixer/cmake_install.cmake")
  include("/home/azzathesis/ardupilot/build/px4-v2/modules/PX4Firmware/src/modules/uORB/cmake_install.cmake")
  include("/home/azzathesis/ardupilot/build/px4-v2/modules/PX4Firmware/src/drivers/boards/px4fmu-v2/cmake_install.cmake")
  include("/home/azzathesis/ardupilot/build/px4-v2/modules/PX4Firmware/src/drivers/pwm_input/cmake_install.cmake")
  include("/home/azzathesis/ardupilot/build/px4-v2/modules/PX4Firmware/src/drivers/px4io/cmake_install.cmake")
  include("/home/azzathesis/ardupilot/build/px4-v2/modules/PX4Firmware/src/firmware/nuttx/cmake_install.cmake")
  include("/home/azzathesis/ardupilot/build/px4-v2/modules/PX4Firmware/src/modules/px4iofirmware/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/azzathesis/ardupilot/build/px4-v2/modules/PX4Firmware/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
