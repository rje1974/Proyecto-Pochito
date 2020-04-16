#!/usr/bin/env python

import rospy
from math import atan2, isnan, pi, radians
from nav_msgs.msg import Odometry
from geometry_msgs.msg import TwistStamped, Quaternion, QuaternionStamped
from tf.transformations import euler_from_quaternion, quaternion_from_euler
from sensor_msgs.msg import Imu
from std_msgs.msg import Float64

# RMC Bearing Heading of course is measured from the y-axis, positive CW.
# Auto calculate dec  https://github.com/clearpathrobotics/declination

# Need 
def convert_deg_to_rads(degs):
    return radians(degs)

class HeadingCalibration():

    def __init__(self):
        self.current_heading = QuaternionStamped()
        self.best_heading = QuaternionStamped()
        self.vel_sub = rospy.Subscriber('tcpvel', TwistStamped, self.vel_callback)

        self.head_pub = rospy.Publisher('heading', QuaternionStamped, queue_size=1)

        self.VelYaw = 0.0

        self.heading_last_good = QuaternionStamped()

    def yaw_to_degree(self, yaw):
            # Radians to Degrees 
            yaw   *= 180.0 / pi
            # Ensure yaw stays between 0 and 360
            if yaw < 0: 
                yaw += 360.0
            return yaw
            
    def vel_callback(self, msg):
        y = float(msg.twist.linear.y)
        x = float(msg.twist.linear.x)
        # check for nan values
        if isnan(x) or isnan(y):
            # If vel is nan then use last good heading
            self.current_heading = self.heading_last_good
        else:
            yaw = float(atan2(y,x))
            #yaw += 1.5708
            yaw = self.yaw_to_degree(yaw)

            self.VelYaw = yaw 
            
            # Degrees to Radians
            yaw   *=  pi/180.0

            self.current_heading.header.stamp = rospy.get_rostime()
            self.current_heading.header.frame_id = 'gps'
            q = quaternion_from_euler(0, 0, yaw)
            self.current_heading.quaternion.x = q[0]
            self.current_heading.quaternion.y = q[1]
            self.current_heading.quaternion.z = q[2]
            self.current_heading.quaternion.w = q[3]

            self.heading_last_good = self.current_heading


    def publish_heading(self):
        rate = rospy.Rate(5)
        while not rospy.is_shutdown():

            self.head_pub.publish(self.current_heading)

            rate.sleep()
        rospy.spin()


if __name__ == '__main__':
    rospy.init_node('heading_compare_node')
    heading_object = HeadingCalibration()
    try:
        heading_object.publish_heading()
    except rospy.ROSInterruptException:
        pass
