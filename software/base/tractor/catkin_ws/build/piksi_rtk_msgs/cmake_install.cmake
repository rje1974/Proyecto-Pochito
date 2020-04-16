# Install script for directory: /root/catkin_ws/src/ethz_piksi_ros/piksi_rtk_msgs

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/root/catkin_ws/install")
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

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
        file(MAKE_DIRECTORY "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
      endif()
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin")
        file(WRITE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin" "")
      endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/root/catkin_ws/install/_setup_util.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/root/catkin_ws/install" TYPE PROGRAM FILES "/root/catkin_ws/build/piksi_rtk_msgs/catkin_generated/installspace/_setup_util.py")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/root/catkin_ws/install/env.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/root/catkin_ws/install" TYPE PROGRAM FILES "/root/catkin_ws/build/piksi_rtk_msgs/catkin_generated/installspace/env.sh")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/root/catkin_ws/install/setup.bash;/root/catkin_ws/install/local_setup.bash")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/root/catkin_ws/install" TYPE FILE FILES
    "/root/catkin_ws/build/piksi_rtk_msgs/catkin_generated/installspace/setup.bash"
    "/root/catkin_ws/build/piksi_rtk_msgs/catkin_generated/installspace/local_setup.bash"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/root/catkin_ws/install/setup.sh;/root/catkin_ws/install/local_setup.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/root/catkin_ws/install" TYPE FILE FILES
    "/root/catkin_ws/build/piksi_rtk_msgs/catkin_generated/installspace/setup.sh"
    "/root/catkin_ws/build/piksi_rtk_msgs/catkin_generated/installspace/local_setup.sh"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/root/catkin_ws/install/setup.zsh;/root/catkin_ws/install/local_setup.zsh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/root/catkin_ws/install" TYPE FILE FILES
    "/root/catkin_ws/build/piksi_rtk_msgs/catkin_generated/installspace/setup.zsh"
    "/root/catkin_ws/build/piksi_rtk_msgs/catkin_generated/installspace/local_setup.zsh"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/root/catkin_ws/install/.rosinstall")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/root/catkin_ws/install" TYPE FILE FILES "/root/catkin_ws/build/piksi_rtk_msgs/catkin_generated/installspace/.rosinstall")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/piksi_rtk_msgs/msg" TYPE FILE FILES
    "/root/catkin_ws/src/ethz_piksi_ros/piksi_rtk_msgs/msg/AgeOfCorrections.msg"
    "/root/catkin_ws/src/ethz_piksi_ros/piksi_rtk_msgs/msg/BaselineEcef.msg"
    "/root/catkin_ws/src/ethz_piksi_ros/piksi_rtk_msgs/msg/BaselineHeading.msg"
    "/root/catkin_ws/src/ethz_piksi_ros/piksi_rtk_msgs/msg/BaselineNed.msg"
    "/root/catkin_ws/src/ethz_piksi_ros/piksi_rtk_msgs/msg/BasePosEcef.msg"
    "/root/catkin_ws/src/ethz_piksi_ros/piksi_rtk_msgs/msg/BasePosLlh.msg"
    "/root/catkin_ws/src/ethz_piksi_ros/piksi_rtk_msgs/msg/DeviceMonitor_V2_3_15.msg"
    "/root/catkin_ws/src/ethz_piksi_ros/piksi_rtk_msgs/msg/Dops.msg"
    "/root/catkin_ws/src/ethz_piksi_ros/piksi_rtk_msgs/msg/DopsMulti.msg"
    "/root/catkin_ws/src/ethz_piksi_ros/piksi_rtk_msgs/msg/GpsTime.msg"
    "/root/catkin_ws/src/ethz_piksi_ros/piksi_rtk_msgs/msg/GpsTimeMulti.msg"
    "/root/catkin_ws/src/ethz_piksi_ros/piksi_rtk_msgs/msg/Heartbeat.msg"
    "/root/catkin_ws/src/ethz_piksi_ros/piksi_rtk_msgs/msg/ImuAuxMulti.msg"
    "/root/catkin_ws/src/ethz_piksi_ros/piksi_rtk_msgs/msg/ImuRawMulti.msg"
    "/root/catkin_ws/src/ethz_piksi_ros/piksi_rtk_msgs/msg/InfoWifiCorrections.msg"
    "/root/catkin_ws/src/ethz_piksi_ros/piksi_rtk_msgs/msg/Log.msg"
    "/root/catkin_ws/src/ethz_piksi_ros/piksi_rtk_msgs/msg/MagRaw.msg"
    "/root/catkin_ws/src/ethz_piksi_ros/piksi_rtk_msgs/msg/MeasurementState_V2_4_1.msg"
    "/root/catkin_ws/src/ethz_piksi_ros/piksi_rtk_msgs/msg/Observation.msg"
    "/root/catkin_ws/src/ethz_piksi_ros/piksi_rtk_msgs/msg/PosEcef.msg"
    "/root/catkin_ws/src/ethz_piksi_ros/piksi_rtk_msgs/msg/PosLlh.msg"
    "/root/catkin_ws/src/ethz_piksi_ros/piksi_rtk_msgs/msg/PosLlhMulti.msg"
    "/root/catkin_ws/src/ethz_piksi_ros/piksi_rtk_msgs/msg/ReceiverState.msg"
    "/root/catkin_ws/src/ethz_piksi_ros/piksi_rtk_msgs/msg/ReceiverState_V2_2_15.msg"
    "/root/catkin_ws/src/ethz_piksi_ros/piksi_rtk_msgs/msg/ReceiverState_V2_3_15.msg"
    "/root/catkin_ws/src/ethz_piksi_ros/piksi_rtk_msgs/msg/ReceiverState_V2_4_1.msg"
    "/root/catkin_ws/src/ethz_piksi_ros/piksi_rtk_msgs/msg/TrackingState.msg"
    "/root/catkin_ws/src/ethz_piksi_ros/piksi_rtk_msgs/msg/TrackingState_V2_2_15.msg"
    "/root/catkin_ws/src/ethz_piksi_ros/piksi_rtk_msgs/msg/TrackingState_V2_3_15.msg"
    "/root/catkin_ws/src/ethz_piksi_ros/piksi_rtk_msgs/msg/UartState.msg"
    "/root/catkin_ws/src/ethz_piksi_ros/piksi_rtk_msgs/msg/UartState_V2_3_15.msg"
    "/root/catkin_ws/src/ethz_piksi_ros/piksi_rtk_msgs/msg/UtcTimeMulti.msg"
    "/root/catkin_ws/src/ethz_piksi_ros/piksi_rtk_msgs/msg/VelEcef.msg"
    "/root/catkin_ws/src/ethz_piksi_ros/piksi_rtk_msgs/msg/VelNed.msg"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/piksi_rtk_msgs/srv" TYPE FILE FILES
    "/root/catkin_ws/src/ethz_piksi_ros/piksi_rtk_msgs/srv/SettingsWrite.srv"
    "/root/catkin_ws/src/ethz_piksi_ros/piksi_rtk_msgs/srv/SettingsReadReq.srv"
    "/root/catkin_ws/src/ethz_piksi_ros/piksi_rtk_msgs/srv/SettingsReadResp.srv"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/piksi_rtk_msgs/cmake" TYPE FILE FILES "/root/catkin_ws/build/piksi_rtk_msgs/catkin_generated/installspace/piksi_rtk_msgs-msg-paths.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/root/catkin_ws/devel/.private/piksi_rtk_msgs/include/piksi_rtk_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/root/catkin_ws/devel/.private/piksi_rtk_msgs/share/roseus/ros/piksi_rtk_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/root/catkin_ws/devel/.private/piksi_rtk_msgs/share/common-lisp/ros/piksi_rtk_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/root/catkin_ws/devel/.private/piksi_rtk_msgs/share/gennodejs/ros/piksi_rtk_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND "/usr/bin/python" -m compileall "/root/catkin_ws/devel/.private/piksi_rtk_msgs/lib/python2.7/dist-packages/piksi_rtk_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/root/catkin_ws/devel/.private/piksi_rtk_msgs/lib/python2.7/dist-packages/piksi_rtk_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/root/catkin_ws/build/piksi_rtk_msgs/catkin_generated/installspace/piksi_rtk_msgs.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/piksi_rtk_msgs/cmake" TYPE FILE FILES "/root/catkin_ws/build/piksi_rtk_msgs/catkin_generated/installspace/piksi_rtk_msgs-msg-extras.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/piksi_rtk_msgs/cmake" TYPE FILE FILES
    "/root/catkin_ws/build/piksi_rtk_msgs/catkin_generated/installspace/piksi_rtk_msgsConfig.cmake"
    "/root/catkin_ws/build/piksi_rtk_msgs/catkin_generated/installspace/piksi_rtk_msgsConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/piksi_rtk_msgs" TYPE FILE FILES "/root/catkin_ws/src/ethz_piksi_ros/piksi_rtk_msgs/package.xml")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/root/catkin_ws/build/piksi_rtk_msgs/gtest/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/root/catkin_ws/build/piksi_rtk_msgs/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
