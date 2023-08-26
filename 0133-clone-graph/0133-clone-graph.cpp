/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*>m;//{{old,new}}
    Node* cloneGraph(Node* node) {
        // DFS T:O(N) S:O(N)-O(log N)
        if(!node)
            return nullptr;
        if(m.count(node))
            return m[node];
        m[node] = new Node(node->val);
        for(Node* neighbor : node->neighbors){
            m[node]->neighbors.push_back(cloneGraph(neighbor));
        }
        return m[node];
    }
};