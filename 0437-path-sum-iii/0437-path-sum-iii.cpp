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
    int dfs(TreeNode* root, int t,long pre,unordered_map<long,int>&m) {
        if(!root)
            return 0;
        pre+=root->val;
        int ans=0;
        if(m.count(pre-t)){
            //cout << root->val <<":"<<m[pre-t]<<endl;
            ans+=m[pre-t];
        }
        m[pre]++;
        ans+=dfs(root->left,t,pre,m);
        ans+=dfs(root->right,t,pre,m);
        m[pre]--;
        return ans;
    }
    int pathSum(TreeNode* root, int t) {
        unordered_map<long,int>m;
        m[0]=1;
        return dfs(root,t,0,m);
    }
};