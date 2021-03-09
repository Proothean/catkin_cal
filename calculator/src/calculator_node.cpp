#include "../include/calculator/calculator.h"
#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include "../include/calculator/tic_toc.h"
using namespace std;
Calculator calculator;
int main(int argc,char **argv){
	ros::init(argc,argv,"calculator_node");
	ros::NodeHandle nh;
	ros::Publisher pub_result = nh.advertise<std_msgs::Int32>("result", 1000);

	std_msgs::Int32 msg;
	string input;
	long result;

  	ROS_INFO_STREAM("type expression");
  	cin>>input;
	TicToc t;
	ROS_INFO_STREAM("calculate "<<input<<"..."<<endl);
	result=calculator.calculate(input);
	ROS_INFO_STREAM("result = "<<result<<endl);
	ROS_INFO("time costs: %f", t.toc());
	msg.data=result;
	pub_result.publish(msg);

	ros::spinOnce();	
return 0;
	
}
 
