/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node *pre=nullptr;
    //.  4
    // 2  5
    //1 3
    //dfs(4) pre=d
    // dfs(2) pre=d
    //  dfs(1) pre=d=>pre=1
    //         pre=1=>pre=2
    //. dfs(3) pre=2=>pre=3
    void dfs(Node* root){
        if(!root)
            return;
        Node *left=root->left,*right=root->right;
        dfs(left);
        pre->right=root;
        //pre->left=pre->pre
        root->left=pre;        
        //root->right=nullptr;
        cout << pre->val <<"->" << root->val <<endl;
        pre=root;
        dfs(right);
    }
    Node* treeToDoublyList(Node* root) {
        if(!root)
            return nullptr;
        pre=new Node(-1);//dummy
        Node* head=pre;
        dfs(root);
        //cout << head->val <<endl;
        //cout << pre->val <<endl;
        head=head->right;
        pre->right=head;
        head->left=pre;
        /*while(head){
            cout << head->val <<endl;
            head=head->right;
        }*/
        return head;
    }
};