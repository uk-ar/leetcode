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
    TreeNode*pre=nullptr;
    int n = 1;
    int kthSmallest(TreeNode* root, int k) {        
        if(!root)
            return -1;
        int l = kthSmallest(root->left,k);
        if(l>=0)
            return l;
        if(n == k)
            return root->val;
        n++;
        int r = kthSmallest(root->right,k);
        return r;
    }
};