# catkin_cal

## Calculator based on ROS
  **catkin_cal** is a calculator which implement `long signed int` addition and subtraction. The bracket nesting is also detected. This project is just a practice of [ROS_tutorials](http://wiki.ros.org/ROS/Tutorials) from step 1 to 16 and [ros_test](http://wiki.ros.org/rostest).
  
  
## Prerequisites
 Ubuntu and [ROS Installation](http://wiki.ros.org/melodic/Installation) Ubuntu 16.04 or newer ROS Kinetic or newer. 

## How to build and execution
1.Clone the repository and catkin_make:
```
    cd ~/catkin_ws/src
    git clone git@github.com:Proothean/catkin_cal.git
    cd ../
    catkin_make
    source ~/catkin_ws/devel/setup.bash
```
2.You can type `rosrun` command to execute single node or directly type following `roslaunch` command to execute all nodes.
```
    roslaunch calculator calculator.launch 
```
This command may launch two nodes which are publisher and subscriber. The following messages may show on the terminal:
```
    [ INFO]:  type expression
    [ INFO]:  subscriber init..
    [ INFO]:  done!  
```
Then you can dirctly type expression you want to calculate on terminal e.g. 1+(-2+(3-4-(4+3))), and you will see the feedback from publisher.
```
  [ INFO]:  calculate 1+(-2+(3-4-(4+3)))...
  [ INFO]:  result = -9
  [ INFO]:  time costs: 0.270113
  [ INFO]:  subscriber result is: [-9]
```
3.Unit test can be executed with command:
```
    rostest calculator test_calculator.launch 
```
Then you will see the test report:
```
    [Testcase: testtest_calculator] ... ok

[ROSTEST]-----------------------------------------------------------------------

[calculator.rosunit-test_calculator/testCase1][passed]
[calculator.rosunit-test_calculator/testCase2][passed]
[calculator.rosunit-test_calculator/testCase3][passed]
[calculator.rosunit-test_calculator/testCase4][passed]
[calculator.rosunit-test_calculator/testCase5][passed]

SUMMARY
 * RESULT: SUCCESS
 * TESTS: 5
 * ERRORS: 0
 * FAILURES: 0
```
You can also customize your testbench by editing source code which locate in `/test/test_calculator.cpp`.
## Calculator
  Source codes are located in `catkin_ws/src/calculator/src`. The calculator is mainly implemented with `stack` in `calculator.cpp/class calculator`. `calculator_node.cpp` construct a publisher node which communicates with another subscriber_node located in`catkin_ws/src/subscriber_node/src/subscriber.cpp`. The subscriber will receive the result and show on the terminal.

## Unit test
  5 Unit tests are designed to test the implementation of calculator. The testbench are 
  ```
    string input1="2+4";
    string input2="-2+4";
    string input3="2+(-2)";
    string input4="(-2)-(-4)";
    string input5="((-2)+(-5))";
  ```
This test didn't include the over-flow test , which could be extended in the future.
