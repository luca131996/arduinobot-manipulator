#!/usr/bin/env python3
import rospy 
from std_msgs.msg import String

if __name__ == '__main__':
	rospy.init_node("simple_publisher_py", anonymous=True)
	pub = rospy.Publisher("chatter", String, queue_size=10)

	r = rospy.Rate(10) #Hz, sending frequency of the msg

	counter = 0

	while not rospy.is_shutdown():
		hello_msg = f'Hello World, Im a Robot {counter}'
		pub.publish(hello_msg)
		r.sleep()

		counter +=1