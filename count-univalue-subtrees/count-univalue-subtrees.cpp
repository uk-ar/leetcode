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
    bool dfs(TreeNode* root,int p,int &ans) {
        if(!root)
            return true;
        bool l=dfs(root->left ,root->val,ans);
        bool r=dfs(root->right,root->val,ans);
        if(l&&r)
            ans++;
        return (l&&r&&root->val==p);
    }
    int countUnivalSubtrees(TreeNode* root) {
        if(!root)
            return 0;
        int ans=0;
        dfs(root,root->val,ans);
        return ans;
    }
};