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
    vector<int> postorder(Node* root) {
        vector<int>ans;
        vector<Node*>st;
        if(!root)
            return ans;
        st.push_back(root);
        //   1
        // 2 5 6
        //3 4
        //   6
        // 3 4 5
        //1 2
        while(!st.empty()){
            Node*n=st.back();st.pop_back();
            ans.push_back(n->val);//[6,5,4,3,2,1]            
            for(auto e:n->children)
                st.push_back(e);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    void dfs(Node*root,vector<int>&ans){
        if(!root)
            return;
        for(auto e:root->children)
            dfs(e,ans);
        ans.push_back(root->val);
    }
    vector<int> postorder_rec(Node* root) {
        vector<int>ans;
        dfs(root,ans);
        return ans;
    }
};