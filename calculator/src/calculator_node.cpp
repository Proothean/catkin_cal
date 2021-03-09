#include "../include/calculator/calculator.h"
#include <ros/ros.h>
using namespace std;
Calculator calculator;
int main(int argc,char **argv){
	ros::init(argc,argv,"calculator_node");
	ros::NodeHandle nh;
	string input;
	int result;
  	ROS_INFO_STREAM("type expression");
  	cin>>input;
	result=calculator.calculate(input);
	ROS_INFO_STREAM("result = "<<result<<endl);
	
}
 
