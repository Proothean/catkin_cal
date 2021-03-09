#include "../include/calculator/calculator.h"
#include <ros/ros.h>
#include <std_msgs/Int32.h>
using namespace std;
Calculator calculator;
int main(int argc,char **argv){
	ros::init(argc,argv,"calculator_node");
	ros::NodeHandle nh;
	ros::Publisher pub_result = nh.advertise<std_msgs::Int32>("result", 1000);
	ros::Rate rate(100);
	std_msgs::Int32 msg;
	string input;
	long result;
  	ROS_INFO_STREAM("type expression");
  	cin>>input;
	ROS_INFO_STREAM("calculate "<<input<<"..."<<endl);
	result=calculator.calculate(input);
	ROS_INFO_STREAM("result = "<<result<<endl);
	msg.data=result;
	pub_result.publish(msg);
	ros::spinOnce();	
return 0;
	
}
 
