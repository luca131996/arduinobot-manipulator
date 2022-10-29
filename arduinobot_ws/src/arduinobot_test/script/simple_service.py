#!/usr/bin/env python3
import rospy

from arduinobot_test.srv import AddTwoInts, AddTwoIntsResponse

def add_two_int(req):
	rospy.loginfo(f"Ready to RUMBLEEEE: sum {req.a} and {req.b}")
	return AddTwoIntsResponse(req.a + req.b)


if __name__ == '__main__':
	rospy.init_node("simple_service")
	service = rospy.Service('add_two_ints', AddTwoInts, add_two_int)

	rospy.loginfo("The service is ready to RUMBLEEEE (just add two ints)")

	rospy.spin()