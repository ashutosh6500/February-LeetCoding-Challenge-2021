/*
Question:
Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
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
class Solution {
public:
    int cnt;
    Solution()
    {
        cnt=0;
    }
    void rev_inorder(TreeNode * root) //Reverse Inorder traversal
    {
        if(root==NULL)
            return;
        rev_inorder(root->right);
        cnt+=root->val;
        root->val=cnt;
        rev_inorder(root->left);
    }
    TreeNode* convertBST(TreeNode* root)
    {
        rev_inorder(root);
        return root;
    }
};
