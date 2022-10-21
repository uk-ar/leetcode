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
    unordered_map<TreeNode*,int>m;
    int find(TreeNode*root,TreeNode*target){
        if(!root)
            return INT_MAX;
        if(root==target)
            return m[root]=0;
        int ans=find(root->left,target);
        ans = min(ans,find(root->right,target));
        if(ans==INT_MAX)
            return ans;
        return m[root]=ans+1;
    }
    vector<int>ans;
    void rec(TreeNode*root,int t,int k){
        if(!root)
            return;
        if(m.count(root))
            t=m[root];
        if(t==k)
            ans.push_back(root->val);
        rec(root->left,t+1,k);
        rec(root->right,t+1,k);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        find(root,target);
        rec(root,INT_MAX,k);
        return ans;
    }
};