/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int>ans;
    void getChild(TreeNode* root,int k) {
        if(!root)
            return;
        if(k==0)
            ans.push_back(root->val);
        getChild(root->left,k-1);
        getChild(root->right,k-1);
    }
    int getParent(TreeNode* root, TreeNode* target, int k) {
        if(!root)
            return -1;
        if(root==target){
            if(0==k)
                ans.push_back(root->val);
            getChild(root->left,k-1);
            getChild(root->right,k-1);
            return 1;
        }     
        int l=getParent(root->left,target,k);
        if(l!=-1){
            if(l==k)
                ans.push_back(root->val);
            l++;
            getChild(root->right,k-l);
            return l;
        }
        l=getParent(root->right,target,k);
        if(l!=-1){
            if(l==k)
                ans.push_back(root->val);
            l++;
            getChild(root->left,k-l);
            return l;
        }
        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        getParent(root,target,k);
        return ans;
    }
};