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
class BSTIterator {
public:
    TreeNode*r;
    vector<TreeNode*>v;
    BSTIterator(TreeNode* root) {
        r=root; 
        //hasNext();
    }
    
    int next() {
        if(!hasNext())
            return -1;
        while(r){
            v.push_back(r);
            r=r->left;       
        }
        r=v.back();v.pop_back();
        int ans=r->val;
        r=r->right;
        return ans;
    }
    
    bool hasNext() {
        return !v.empty() or r;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */