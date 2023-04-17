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
    bool isMatch(TreeNode* root, TreeNode* subRoot) {
        if(!root and !subRoot)
            return true;
        if(!root or !subRoot or root->val!=subRoot->val)
            return false;
        return isMatch(root->left,subRoot->left) and 
            isMatch(root->right,subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool ans=false;
        if(!root and !subRoot)
            return true;
        if(!root or !subRoot)
            return false;
        if(root->val==subRoot->val)
            ans=isMatch(root,subRoot);
        return ans || isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};