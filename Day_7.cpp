/*
Question:
Given a string s and a character c that occurs in s, return an array of integers answer where answer.
length == s.length and answer[i] is the shortest distance from s[i] to the character c in s.

Example 1:

Input: s = "loveleetcode", c = "e"
Output: [3,2,1,0,1,0,0,1,2,2,1,0]
 */
class Solution {
public:
    vector<int> shortestToChar(string s, char c) //Solved by Brute Force
    {
        vector<int>v,v1;
        for(int i=0;i<s.size();i++) //For storing indexes of c in string s
        {
            if(s[i]==c)
                v1.push_back(i);
        }
        int mi=INT_MAX;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==c)
                v.push_back(0);
            else
            {
                for(auto u:v1)
                {
                    if(abs(u-i) < mi)
                        mi=abs(u-i);
                }
                v.push_back(mi);
                mi=INT_MAX;
            }
        }
        return v;
    }
};
