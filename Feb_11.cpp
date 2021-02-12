/*
Question:
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 */

class Solution {
public:
    bool isAnagram(string s, string t)
    {
        if(s.size() != t.size())
            return false;
        if(s==t)
            return true;
        unordered_map<char,int>oc; //hashmap
        for(auto e:s)
            oc[e]++;
        for(auto p:t)
        {
            oc[p]--;
            if(oc[p] <0)
                return false;
        }
        return oc.size();
    }
};
