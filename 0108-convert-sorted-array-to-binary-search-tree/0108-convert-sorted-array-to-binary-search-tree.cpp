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
    TreeNode *cons(vector<int>& n,int l,int r) {
        if(l>=r)
            return nullptr;
        int m=l+(r-l)/2;        
        TreeNode*ans=new TreeNode(n[m]);
        ans->left =cons(n,l,m);
        ans->right=cons(n,m+1,r);
        return ans;
    }
    TreeNode* sortedArrayToBST(vector<int>& n) {
        return cons(n,0,n.size());
    }
};