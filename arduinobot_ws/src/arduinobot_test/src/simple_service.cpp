#include "ros/ros.h"
#include "arduinobot_test/AddTwoInts.h"

bool add(arduinobot_test::AddTwoInts::Request &req, arduinobot_test::AddTwoInts::Response &res)
{
	ROS_INFO("The service is ready to RUMBLEEEEE (just adding some ints :( %d and %d))", (int)req.a, (int)req.b);
	res.sum = req.a + req.b;

	return true;
}


int main(int argc, char **argv)
{
	ros::init(argc, argv, "simple_service");
	ros::NodeHandle n;
	ros::ServiceServer service = n.advertiseService("add_two_ints", add);

	ROS_INFO("The service is ready to RUMBLEEEEE (just adding some ints :( ))");

	ros::spin();

	return 0;
}