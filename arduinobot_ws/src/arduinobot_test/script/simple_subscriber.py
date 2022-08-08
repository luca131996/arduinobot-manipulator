#!/usr/bin/env python3
import rospy
from std_msgs.msg import String

def msgCallback(data):
	rospy.loginfo(f"I am alive! I can hear {data.data}")


if __name__ == '__main__':
	rospy.init_node("listener", anonymous=True)
	rospy.Subscriber("chatter", String, msgCallback) #I have to specify from which topic I need to receive msgs
	
	rospy.spin() #keep alive and listening this node