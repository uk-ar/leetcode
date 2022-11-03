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
    TreeNode*l=nullptr,*r=nullptr,*pre=nullptr;
    void dfs(TreeNode*root){
        if(!root)
            return;
        dfs(root->left);
        if(pre and pre->val>root->val){
            if(!l){
                l=pre;
                r=root;
            }else{
                r=root;
            }
        }
        pre=root;
        dfs(root->right);
    }
    void recoverTree(TreeNode* root) {
        dfs(root);
        swap(l->val,r->val);
        return;
    }
};