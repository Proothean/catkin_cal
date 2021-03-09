#include "../include/calculator/calculator.h"
#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <gtest/gtest.h>
#define TEST_EXPRESSION(a) EXPECT_EQ((a), Calculator::calculate(#a))
Calculator calculator;
string input1="2+4";
string input2="-2+4";
string input3="2+(-2)";
string input4="(-2)-(-4)";
string input5="((-2)+(-5))";
string input6="2147483640+10";
    // Declare a test
    TEST(TestSuite, testCase1)
    {	
	
     EXPECT_EQ(6, calculator.calculate(input1));
   }
   
   // Declare another test
    TEST(TestSuite, testCase2)
    {	
	
     EXPECT_EQ(2, calculator.calculate(input2));
   }
    TEST(TestSuite, testCase3)
    {	
	
     EXPECT_EQ(0, calculator.calculate(input3));
   }
    TEST(TestSuite, testCase4)
    {	
	
     EXPECT_EQ(2, calculator.calculate(input4));
   }
    TEST(TestSuite, testCase5)
    {	
	
     EXPECT_EQ(-7, calculator.calculate(input5));
   }
    TEST(TestSuite, testCase6)
    {	
	
     EXPECT_EQ(2147483647, calculator.calculate(input6));
   }
int main(int argc, char **argv){
     testing::InitGoogleTest(&argc, argv);
     ros::init(argc, argv, "tester");
     ros::NodeHandle nh;
     return RUN_ALL_TESTS();
   }
