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
    int dfs(TreeNode* root, int k,int &c) {
        if(!root)
            return -1;        
        int ans=dfs(root->left,k,c);
        if(ans!=-1)
            return ans;
        if(c==k)
            return root->val;
        c++;
        return dfs(root->right,k,c);
    }
    int kthSmallest(TreeNode* root, int k) {
        int c=1;
        return dfs(root,k,c);
    }
};