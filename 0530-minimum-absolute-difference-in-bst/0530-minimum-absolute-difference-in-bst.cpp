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
    int getMinimumDifference(TreeNode* root) {
        TreeNode*pre=nullptr;
        vector<TreeNode*>st;
        int ans=INT_MAX;
        while(!st.empty() or root){
            if(root){
                st.push_back(root);
                //pre=root;
                root=root->left;
            }else{                
                root=st.back();st.pop_back();
                if(pre){
                    cout << pre->val <<":"<< root->val <<endl;
                    ans=min(ans,root->val-pre->val);
                }
                pre=root;
                root=root->right;
            }
        }
        return ans;
    }
};