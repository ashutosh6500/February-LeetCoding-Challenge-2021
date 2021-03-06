/*
Question:
A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, these are arithmetic sequences:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.

1, 1, 2, 5, 7

A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.

A slice (P, Q) of the array A is called arithmetic if the sequence:
A[P], A[P + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

The function should return the number of arithmetic slices in the array A.


Example:

A = [1, 2, 3, 4]

return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
*/

class Solution {
public:
    int Number_of_subarrays(int n)
    {
        if(n==3)
            return 1;
        if(n<3)
            return 0;
        return((n*(n+1) /2) - (2*n - 1));
    }
    int numberOfArithmeticSlices(vector<int>& A)
    {
        int cnt=2,ans=0;
        if(A.size()<3)
            return 0;
        int p=A[1] - A[0];
        for(int i=1;i<A.size()-1;i++)
        {
            if(p == A[i+1]-A[i])
            {
                cnt++;
                if(i==A.size()-2)
                    ans+=Number_of_subarrays(cnt);
            }
            else
            {
                ans+=Number_of_subarrays(cnt);
                p=A[i+1]-A[i];
                cnt=2;
            }
        }
        return ans;
    }
};
