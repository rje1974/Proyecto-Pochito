#!/usr/bin/env python
# Me lo choricie de aqui y le hice algunos retoques.
# http://library.isr.ist.utl.pt/docs/roswiki/mini_max(2f)Tutorials(2f)Moving(20)the(20)Base.html
# Example code of how to move a robot forward for 3 seconds.

import rospy

# recall: robots generally take base movement commands on a topic
#  called "cmd_vel" using a message type "geometry_msgs/Twist"

from geometry_msgs.msg import Twist

x_speed = 6.0  # 3 m/s Creo que hay que conservar la sintaxis de como se escribe la velocidad

# this quick check means that the following code runs ONLY if this is the
# main file -- if we "import move" in another file, this code will not execute.
if __name__=="__main__":

    # first thing, init a node!
    rospy.init_node('move')

    # publish to cmd_vel
    p = rospy.Publisher('cmd_vel', Twist, queue_size=1)

    # Creamos el primer mensaje de twist que seria un VAMO PA DELANTE
    twist = Twist()
    twist.linear.x = x_speed;                   # our forward speed
    twist.linear.y = 0; twist.linear.z = 0;     # we can't use these!
    twist.angular.x = 0; twist.angular.y = 0;   #          or these!
    twist.angular.z = 0.0;                        # no rotation

    # announce move, and publish the message
    rospy.loginfo("Para adelante...")
    for i in range(40):
        p.publish(twist)
        rospy.sleep(0.2) # 30*0.1 = 3.0

x_speed = -6.0  # 3 m/s Creo que hay que conservar la sintaxis de como se escribe la velocidad

# this quick check means that the following code runs ONLY if this is the
# main file -- if we "import move" in another file, this code will not execute.
if __name__=="__main__":

    # first thing, init a node!
    rospy.init_node('move')

    # publish to cmd_vel
    p = rospy.Publisher('cmd_vel', Twist, queue_size=1)

    # Creamos el primer mensaje de twist que seria un VAMO PA DELANTE
    twist = Twist()
    twist.linear.x = x_speed;                   # our forward speed
    twist.linear.y = 0; twist.linear.z = 0;     # we can't use these!
    twist.angular.x = 0; twist.angular.y = 0;   #          or these!
    twist.angular.z = 0.0;                        # no rotation

    # announce move, and publish the message
    rospy.loginfo("Frenando...")
    for i in range(40):
        p.publish(twist)
        rospy.sleep(0.1) # 30*0.1 = 3.0



    # note: everything defaults to 0 in twist, if we don't fill it in, we stop!
    rospy.loginfo("Stopping!")
    p.publish(twist)
