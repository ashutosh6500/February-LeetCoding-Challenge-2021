/*
Question:
Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.


Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
*/
#include <unordered_map>
#include <string>
using namespace std;
#include <iostream>
#include<vector>

class Solution {
public:
    string minRemoveToMakeValid(string s) //Using Stack
    {
        if(s=="")
            return "";
        vector<int>v;    //vector used as stack
        unordered_map<int,int>occ;  //Hashmap to store indices at which parenthesis are invalid.
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                v.push_back(i);
            }
            else if(s[i]==')')
            {
                if(v.size()!=0)
                {
                    v.pop_back();
                }
                else
                    occ[i]++;
            }
        }
        while(! v.empty())
        {
            int u=v.back();
            occ[u]++;
            v.pop_back();
        }
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(! occ[i])
                ans+=s[i];
        }
        return ans;
    }
};
int main()
{
    Solution d;
    cout<<d.minRemoveToMakeValid("((leet)((code)(");
    //output:(leet)(code)
    //Time complexity: O(n) [O(n)+O(n)+O(d) where d is size of stack after first loop]
    return 0;
}
