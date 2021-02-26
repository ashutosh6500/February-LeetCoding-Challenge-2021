/*
Question:
Given two sequences pushed and popped with distinct values, return true if and only if this could have been the result of a sequence of push and pop operations on an initially empty stack.

Example 1:

Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
*/
#include<iostream>
using namespace std;
#include <set>
#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        if(pushed==popped)
            return true;
        int i=0,j=0;
        vector<int>v;
        unordered_map<int,int>occ;
        while(pushed[i]!=popped[j])
        {
            v.push_back(pushed[i]);
            i++;
        }
        occ[popped[j]]++;
        j++;
        while(j<popped.size())
        {
            if(v.size()>0 && popped[j]==v[v.size()-1])
            {
                occ[popped[j]]++;
                j++;
                v.pop_back();
            }
            else
            {
                while(pushed[i]!=popped[j])
                {
                    if(occ[pushed[i]] ==0)
                        v.push_back(pushed[i]);
                    i++;
                    if(i>=popped.size())
                        return false;
                }
                occ[popped[j]]++;
                j++;
            }
        }
        return true;
    }
};
int main()
{
    Solution d;
    vector<int>v{1,2,3,4,5},v1{4,5,3,2,1};
    cout<<d.validateStackSequences(v,v1)<<endl;
    vector<int>v2{1,2,3,4,5},v3{4,3,5,1,2};
    cout<<d.validateStackSequences(v2,v3);
    //output: 1
     //            0
    return 0;
}
