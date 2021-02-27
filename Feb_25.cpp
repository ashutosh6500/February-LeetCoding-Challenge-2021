/*
Question:
Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.
Example 1:

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Example 2:

Input: nums = [1,2,3,4]
Output: 0
Constraints:

1 <= nums.length <= 104
-105 <= nums[i] <= 105
*/
#include<iostream>
using namespace std;
#include <set>
#include <string>
#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>


class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) //O(nlog(n))+O(n)+O(n)
    {
        vector<int>tmp(nums);
        sort(tmp.begin(),tmp.end()); //O(nlog(n))
        int l,r;
        for(int i=0;i<nums.size();i++) //O(n)
        {
            if(nums[i]!=tmp[i])
            {
                l=i;
                break;
            }
        }
        for(int i=nums.size()-1;i>=0;i--) //O(n)
        {
            if(nums[i]!=tmp[i])
            {
                r=i;
                break;
            }
        }
        return (r-l +1)<=0 ? 0 : (r-l +1);
    }
};
int main()
{
    Solution d;
    vector<int>v{2,6,4,8,10,9,15};
    cout<<d.findUnsortedSubarray(v);
    //output: 5
    return 0;
}
