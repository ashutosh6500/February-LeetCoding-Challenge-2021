/*
Question:
Write an efficient algorithm that searches for a target value in an m x n integer matrix. The matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true
*/
#include<iostream>
using namespace std;
#include <set>
#include <string>
#include <vector>
#include <map>

class Solution {
public:
    bool binary_search(vector<int>v,int t)
    {
        int l=0,r=v.size()-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(t==v[mid])
                return true;
            if(t<v[mid])
                r=mid-1;
            else
                l=mid+1;
        }
        return false;
    }
    bool searchMatrix_1(vector<vector<int>>& matrix, int target) //Using Binary search(Got TLE on 1 case!)
    {
        int flg=0;
        for(auto e:matrix)
        {
            if(e[0]>target)
                break;
            if(e[0]<=target && e[e.size() -1]>=target)
            {
                if(binary_search(e,target))
                    return true;
            }
        }
        return false;
    }
    bool searchMatrix_2(vector<vector<int>>& matrix, int target) //Accepted O(n+m)
    {
        int x=0,y=matrix[0].size() -1;
        while(x<matrix.size() && y>=0)
        {
            if(matrix[x][y]==target)
                return true;
            if(matrix[x][y] > target)
                y--;
            else
                x++;
        }
        return false;
    }
};
int main()
{
    Solution d;
    vector<vector<int>> vect
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    cout<<d.searchMatrix_2(vect,9);
    //output:1
    return 0;
}
