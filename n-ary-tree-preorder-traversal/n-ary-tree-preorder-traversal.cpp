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

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int>ans;
        vector<Node*>st;
        if(!root)
            return ans;
        st.push_back(root);
        //   1
        // 2 5 6
        //3 4
        while(!st.empty()){
            Node*c=st.back();st.pop_back();
            ans.push_back(c->val);
            reverse(c->children.begin(),c->children.end());
            for(Node* e:c->children){
                st.push_back(e);
            }            
        }        
        return ans;
    }
    void pre(Node* root,vector<int>&ans) {
        if(!root)
            return;
        ans.push_back(root->val);
        for(auto e:root->children)
            pre(e,ans);
    }
    vector<int> preorder_rec(Node* root) {
        vector<int>ans;
        pre(root,ans);
        return ans;
    }
};