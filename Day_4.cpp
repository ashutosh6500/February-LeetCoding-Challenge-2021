/*
Question:
We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.

Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.

A subsequence of array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.
Example 1:

Input: nums = [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].
*/
#include <iostream>
#include <unordered_map>
class Solution {
public:
    int findLHS(vector<int> & nums)
    {
        unordered_map<int,int>occ,occ1;
        int ma=0;
        int cnt=0;
        for(auto e:nums)
            occ[e]++;
        occ1=occ;
        for(auto k:occ)
        {
            if(occ1[k.first +1] >0)
            {
                for(auto o:occ1)
                {
                    if((o.first >=k.first) && (o.first<=k.first +1))
                        cnt+=o.second;
                }
                if(cnt>ma)
                    ma=cnt;
                cnt=0;
            }
        }
        return ma;
    }
};

