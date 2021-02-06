/*
Question:
Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.

In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level, and any multiple consecutive slashes (i.e. '//') are
treated as a single slash '/'. For this problem, any other format of periods such as '...' are treated as file/directory names.

The canonical path should have the following format:

The path starts with a single slash '/'.
Any two directories are separated by a single slash '/'.
The path does not end with a trailing '/'.
The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
Return the simplified canonical path.

Example 1:
Input: path = "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.
*/
#include <iostream>
#include <unordered_map>
#include <string>
class Solution {
public:
    string simplifyPath(string path) //Implemented by using stack concept.Here,I used std::vector as stack.
    {
        int i;
        if(path=="")
            return path;
        vector<string>v;
        string d="";
        for(i=0;i<path.size();i++) //This loop will remove all consecutive duplicates of slashes(/)
        {
            if(path[i]=='/' && d.size()>0 && d[d.size()-1] != '/' && i!=path.size()-1)
                d+=path[i];
            else if(path[i]!='/')
                d+=path[i];
            else if(d.size()==0 && path[i]=='/')
                d+=path[i];
        }
        i=0;
        while(i<d.size())
        {
            string y="";
            while(d[i]!='/' && i<d.size())
            {
                y+=d[i];
                i++;
            }
            i++;
            if(y!=".")
            {
                if(y==".." && v.size()>0)
                {
                    v.pop_back();
                    if(v.size()==0)
                        v.push_back("/");
                }
                else
                {
                    v.push_back(y);
                }
            }
        }
        string f;
        for(i=0;i<v.size();i++)
        {
            f+=v[i];
            if(i!=v.size() -1)
                f+='/';
        }
        string l="";
        if(f.size()>=2)
        {
            if(f[0]=='/' && f[1]=='/')
            {
                for(i=1;i<f.size();i++)
                    l+=f[i];
                return l;
            }
        }
        else if(f=="")
            return "/";
        return f;
    }
};
