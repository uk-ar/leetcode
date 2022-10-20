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
    int getMinimumDifference(TreeNode* root) {
        if(!root)
            return INT_MAX;
        int ans=getMinimumDifference(root->left);
        if(pre){
            ans=min(ans,root->val-pre->val);
        }
        pre=root;
        return min(ans,getMinimumDifference(root->right));
    }
};