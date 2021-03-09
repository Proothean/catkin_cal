#include "../include/calculator/calculator.h"
#include <ros/ros.h>
#define MIN_INT -2147483648;
#define MAX_INT 2147483647;
using namespace std;
Calculator::Calculator() {}
long Calculator::calculate(string& s)
{	
	ROS_INFO_STREAM("BEGIN");
	stack<int> stk;
    	int sign = 1;
        long num = 0, sum = 0;
	long res;
    	for(int i = 0; i < s.size(); ++i)
    	{
    		if(s[i] =='(')
    		{	
                stk.push(sum);
    			stk.push(sign);
                sign = 1;
                sum = 0;
                num = 0;
    		}
    		else if(s[i] =='+')
    		{
    			sum += sign*num;
    			sign = 1;
    			num = 0;
    		}
    		else if(s[i] =='-')
    		{
    			sum += sign*num;
    			sign = -1;
    			num = 0;
    		}
    		else if(s[i] ==')')
    		{	
    			sum += sign*num;
    			sign = stk.top();
    			stk.pop();
                sum = sign*sum + stk.top();
                stk.pop();
    			num = 0;
    		}
    		else if(isdigit(s[i])){
    			num = num*10+s[i]-'0';
			}
    	}

	ROS_INFO_STREAM("FINISH");
	return sum+sign*num;
}
