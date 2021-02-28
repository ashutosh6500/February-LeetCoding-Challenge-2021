/*
Question:
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero, which means losing its fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.

Note:

Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For this problem, assume that your function returns 231 − 1 when the division result overflows.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = truncate(3.33333..) = 3.
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = truncate(-2.33333..) = -2.
*/
#include<iostream>
using namespace std;
#include <set>
#include <string>
#include <vector>
#include <unordered_map>

#include <cmath>
class Solution {
public:
    int divide(int dividend, int divisor)
    {
        long long int result = 0;
        if(dividend == (-2147483648) && divisor == -1) return 2147483647;
        bool rev = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0);
        long long int a = abs((long long int)dividend);
        long long int b = abs((long long int)divisor);

        while(a >= b) {
            long long c = b;
            for(int i=0; a >= c; ++i, c <<= 1)
            {
                a -= c;
                result += (1 << i);
            }
        }
        return rev ? (-result) : (result);
    }
};
int main()
{
    Solution d;
    cout<<d.divide(45,3)<<endl;
    cout<<d.divide(-2147483648,-1);
    //output:
    //     15
    //     2147483647
    return 0;
}
