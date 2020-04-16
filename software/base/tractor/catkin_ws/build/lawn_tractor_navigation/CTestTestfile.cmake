# CMake generated Testfile for 
# Source directory: /root/catkin_ws/src/ros_lawn_tractor/lawn_tractor_navigation
# Build directory: /root/catkin_ws/build/lawn_tractor_navigation
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(_ctest_lawn_tractor_navigation_roslaunch-check_launch "/root/catkin_ws/build/lawn_tractor_navigation/catkin_generated/env_cached.sh" "/usr/bin/python" "/opt/ros/kinetic/share/catkin/cmake/test/run_tests.py" "/root/catkin_ws/build/lawn_tractor_navigation/test_results/lawn_tractor_navigation/roslaunch-check_launch.xml" "--return-code" "/usr/bin/cmake -E make_directory /root/catkin_ws/build/lawn_tractor_navigation/test_results/lawn_tractor_navigation" "/opt/ros/kinetic/share/roslaunch/cmake/../scripts/roslaunch-check -o '/root/catkin_ws/build/lawn_tractor_navigation/test_results/lawn_tractor_navigation/roslaunch-check_launch.xml' '/root/catkin_ws/src/ros_lawn_tractor/lawn_tractor_navigation/launch' ")
subdirs(gtest)
