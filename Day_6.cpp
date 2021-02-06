/*
Question:
Given a binary tree, imagine yourself standing on the right side of it, return the values
of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <deque>
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) //Implemented using Deque container in STL
    {
        vector<int>v;
        int cnt=0;
        if(root==NULL)
            return v;
        deque<TreeNode *>d;
        d.push_back(root);
        while(d.size()!=0)
        {
            int cnt=d.size();
            for(int y=0;y<cnt;y++)
            {
                TreeNode *tmp=d.front();
                d.pop_front();
                if(y==0)
                    v.push_back(tmp->val);
                if(tmp->right != NULL)
                    d.push_back(tmp->right);
                if(tmp->left !=NULL)
                    d.push_back(tmp->left);
            }
        }
        return v;
    }
};
