#include <ros/ros.h>
#include <std_msgs/Int32.h>
using namespace std;
void resultCallback(const std_msgs::Int32::ConstPtr& msg) 
{
  ROS_INFO("subscriber result is: [%d]", msg->data); 
}


int main(int argc,char **argv){
       ROS_INFO("subscriber init..");
	ros::init(argc,argv,"subscriber_node");
	ros::NodeHandle scnh;
	ros::Subscriber sub = scnh.subscribe("result", 1000, resultCallback);
	ROS_INFO("done!");
	ros::spin();
	

	return 0;
	
}
 
