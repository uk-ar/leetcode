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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // BFS O(n) O(n) - O(logN)
        vector<vector<int>>ans;
        if(!root)
            return ans;
        deque<TreeNode*>q({root});
        while(q.size()>0){
            int n = q.size();
            vector<int>temp;
            while(n--){
                TreeNode* e = q.front();q.pop_front();
                temp.push_back(e->val);
                if(e->left){
                    q.push_back(e->left);
                }
                if(e->right){
                    q.push_back(e->right);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};