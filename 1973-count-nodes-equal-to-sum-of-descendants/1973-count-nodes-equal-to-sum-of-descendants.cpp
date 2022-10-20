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
    int ans=0;
    long sum(TreeNode*root){
        if(!root)
            return 0;
        long l=sum(root->left);
        long r=sum(root->right);
        if(l+r==root->val)
            ans++;
        return l+r+root->val;
    }
    int equalToDescendants(TreeNode* root) {
        sum(root);
        return ans;
    }
};