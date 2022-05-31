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
    vector<vector<int>> levelOrder(Node* root) {
        deque<Node*>q;
        q.push_back(root);
        vector<vector<int>>ans;
        if(!root)
            return ans;        
        while(!q.empty()){
            int n=q.size();
            vector<int>t;
            while(n--){
                Node*e=q.front();q.pop_front();
                for(Node*d:e->children)
                    q.push_back(d);
                t.push_back(e->val);
            }
            ans.push_back(t);
        }
        return ans;
    }
};