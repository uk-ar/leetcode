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
    bool isValidBST(TreeNode* r) {
        if(!r)
            return true;
        bool ret=true;
        ret &= isValidBST(r->left);
        if(pre)
            ret &= (pre->val<r->val);
        pre=r;
        ret &= isValidBST(r->right);
        return ret;
    }
};