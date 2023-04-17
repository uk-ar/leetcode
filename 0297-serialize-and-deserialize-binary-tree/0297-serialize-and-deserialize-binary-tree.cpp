/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "N";
        return to_string(root->val)+" "+
            serialize(root->left)+" "+serialize(root->right);
    }
    TreeNode* dfs(vector<string>&st){
        auto s=st.back();st.pop_back();
        if(s=="N")
            return nullptr;
        TreeNode*ans=new TreeNode(stoi(s));
        ans->left=dfs(st);
        ans->right=dfs(st);
        return ans;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string>st;
        stringstream ss(data);
        string w;
        while(ss>>w){
            st.push_back(w);
        }
        reverse(st.begin(),st.end());
        return dfs(st);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));