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
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        deque<pair<int,TreeNode*>>q;
        q.push_back({1,root});
        int ans=1;
        while(!q.empty()){
            auto [d,n]=q.back();q.pop_back();
            //cout << d <<":"<<n->val<<endl;
            ans=max(ans,d);
            if(n->left)
                q.push_back(make_pair(d+1,n->left));
            if(n->right)
                q.push_back(make_pair(d+1,n->right));
            
        }
        return ans;
    }
};