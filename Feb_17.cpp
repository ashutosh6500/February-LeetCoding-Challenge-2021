/*
Question:
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0).
Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.

Notice that you may not slant the container.
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case,
the max area of water (blue section) the container can contain is 49.
*/

class Solution {
public:
    int maxArea(vector<int>& A)
    {
        int left=0,right=A.size()-1,max,min,max_water,d;
        max_water=(A.size()-1)*(std::min(A[0],A[right]));
        while(left<right)
        {
            if(A[left]>A[right])
            {
                max=left;
                min=right;
            }
            else
            {
                min=left;
                max=right;
            }
            if(left==min)
            {
                left++;
                while(A[left]<A[min] && left<A.size())
                    left++;
            }
            else
            {
                right--;
                while(A[right]<A[min] && right>=0)
                    right--;
            }
            if(left>=right || left>=A.size() || right<0)
                break;
            d=(right-left)*(std::min(A[left],A[right]));
            max_water=std::max(max_water,d);
        }
        return max_water;
    }
};
