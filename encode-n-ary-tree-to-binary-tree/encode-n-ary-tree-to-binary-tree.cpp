/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

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
    //    [1,
    //  3, 2,  4,
    // 5,6]
    //l:dfs(1,[])
    //  l:dfs(N,N)
    //  r:dfs(3,[2,4])
    //   l:dfs(2,[4])
    //   r:dfs(5,[6])
    //.   l:dfs(4,[])
    TreeNode* dfs(Node* root,vector<Node*>&sib){
        if(!root)
            return nullptr;
        TreeNode* ans=new TreeNode(root->val);
        if(!sib.empty()){
            Node*s1=sib.back();sib.pop_back();
            ans->left=dfs(s1,sib);
        }
        if(!root->children.empty()){
            reverse(root->children.begin(),root->children.end());
            Node*c1=root->children.back();root->children.pop_back();
            ans->right=dfs(c1,root->children);
        }
        return ans;
    }
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        vector<Node*>sib;
        return dfs(root,sib);
    }
	
    // Decodes your binary tree to an n-ary tree.
    vector<Node*> dfs(TreeNode* root) {
        if(!root)
            return {nullptr};
        Node* n=new Node(root->val);
        if(root->right){
            vector<Node*> ch=dfs(root->right);
            reverse(ch.begin(),ch.end());
            n->children=ch;
        }
        if(root->left){
            vector<Node*> ans=dfs(root->left);
            ans.push_back(n); 
            return ans;
        }else{
            return {n};
        }
    }
    Node* decode(TreeNode* root) {
        //return nullptr;
        return dfs(root)[0];        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));