
/*
Question:
Write a function that takes an unsigned integer and
returns the number of '1' bits it has (also known as the Hamming weight).
Input: n = 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
*/
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int hammingWeight(uint32_t n)
    {
        int cnt=0;
        while(n)
        {
            if(n & 1)
                cnt++;
            n=n>>1;
        }
        return cnt;
    }
    /*
    Idea is to perform right shift operation to number and when it is odd,it means it contains set bit
    to rightmost part ,thus increment the cnt.Eventually,number will become 0 and return the number.
    */
};
int main()
{
    uint32_t n=00000000000000000000000010000000;
    Solution day_1;
    cout<<day_1.hammingWeight(n);
    return 0;
}
