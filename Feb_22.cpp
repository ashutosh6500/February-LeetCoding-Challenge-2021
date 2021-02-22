/*
Question:
Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

Example 1:
Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

Output:
"apple"
Example 2:
Input:
s = "abpcplea", d = ["a","b","c"]

Output:
"a"
*/
#include<iostream>
using namespace std;
#include <set>
#include <string>
#include <vector>
#include <map>

class Solution {
public:
    bool is_subsequence(string str2, string str1)
    {
        int m = str1.length(), n = str2.length();
        int j = 0;
        for (int i=0; i<n&&j<m; i++)
            if (str1[j] == str2[i])
                j++;
        return (j==str1.size());
    }
    string findLongestWord(string str, vector<string>& d)
    {
        set<string>s;
        multimap<int,string,greater<int> >occ;
        for(auto r:d)
        {
            occ.insert({r.size(),r});
        }
        int len=-1;
        for(auto w:occ)
        {
            if(is_subsequence(str,w.second))
            {
                if(len!= -1 && (w.second.size() < len))
                    break;
                s.insert(w.second);
                   len=w.first;
            }
            if(len!= -1 && (w.second.size() < len))
                break;
        }
        if(s.size()==0)
            return "";
        return *(s.begin());
    }
};
int main()
{
    Solution d;
    vector<string>v{"ale","apple","monkey","plea"};
    cout<<d.findLongestWord("abpcplea",v);
    //output:apple
    return 0;
}
