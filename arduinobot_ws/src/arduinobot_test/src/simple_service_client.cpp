#include "ros/ros.h"
#include "arduinobot_test/AddTwoInts.h"

int main(int argc, char **argv)
{
	ros::init(argc, argv, "add_two_ints_client");

	if(argc != 3)
		{
			ROS_INFO("Wrong number of requested args");
			return -1;
		}

	ros::NodeHandle n;
	ros::ServiceClient client = n.serviceClient<arduinobot_test::AddTwoInts>("add_two_ints");
	arduinobot_test:: AddTwoInts srv;
	srv.request.a = atoll(argv[1]);
	srv.request.b = atoll(argv[2]);
	ROS_INFO("Requesting %d + %d", (int)srv.request.a, (int)srv.request.b);

	if (client.call(srv))
	{
		ROS_INFO("Service Response %d", (int)srv.response.sum);
	}
	else
	{
		ROS_ERROR("Failed to call service add_two_ints");
	}
	return 0;
}