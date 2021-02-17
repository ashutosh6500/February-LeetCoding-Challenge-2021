/*
Question:
Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. You can return the output in any order.
Example 1:

Input: S = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]
Example 2:

Input: S = "3z4"
Output: ["3z4","3Z4"]
*/

class Solution {
public:
    vector<string>v;
    char tolower(char ch)
    {
        if(ch>='a' && ch<='z')
            return ch;
        return (char(int(ch)+32));
    }
    char toupper(char ch)
    {
        if(ch>='A' && ch<='Z')
            return ch;
        return (char(int(ch)-32));
    }
    void recur(string &s,string curr,int i)
    {
        if(curr.size()==s.size())
        {
            v.push_back(curr);
            return;
        }
        if(s[i]>='0' && s[i]<='9')
            recur(s,curr+s[i],i+1);
        else
        {
            recur(s,curr+tolower(s[i]),i+1);
            recur(s,curr+toupper(s[i]),i+1);
        }
    }
    vector<string> letterCasePermutation(string S)
    {
        string curr="";
        recur(S,curr,0);
        return v;
    }
};
