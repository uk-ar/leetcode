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
    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        vector<TreeNode*>ans(2);
        if(!root)
            return ans;
        vector<TreeNode*> l=splitBST(root->left ,target);
        vector<TreeNode*> r=splitBST(root->right,target);
        if(root->val<=target){
            ans[0]=root;//left is all small
            root->left =l[0];
            root->right=r[0];
            ans[1]=r[1];
        }else{
            ans[1]=root;//right is all big
            root->left =l[1];
            root->right=r[1];
            ans[0]=l[0];
        }
        return ans;
    }
};