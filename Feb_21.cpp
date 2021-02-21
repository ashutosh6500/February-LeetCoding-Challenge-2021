/*
Question:
On a broken calculator that has a number showing on its display, we can perform two operations:

Double: Multiply the number on the display by 2, or;
Decrement: Subtract 1 from the number on the display.
Initially, the calculator is displaying the number X.

Return the minimum number of operations needed to display the number Y.



Example 1:

Input: X = 2, Y = 3
Output: 2
Explanation: Use double operation and then decrement operation {2 -> 4 -> 3}.
*/
#include<iostream>
using namespace std;

class Solution {
public:
    int brokenCalc(int x, int y)
    {
        if(x==y)
            return 0;
        else if(x>y)
        {
            return (x-y);
        }
        else
        {
            int cnt=0;
            while(x!=y)
            {
                if(y & 1)
                    y++;
                else
                {
                    if(y>x)
                        y/=2;
                    else
                        return cnt+(x-y);
                }
                cnt++;
            }
            return (cnt);
        }
    }
};
int main()
{
    Solution d;
    cout<<d.brokenCalc(5,8);
    //output:2
    return 0;
}
