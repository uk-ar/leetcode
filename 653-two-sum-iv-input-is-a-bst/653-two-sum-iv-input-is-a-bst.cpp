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
class It{
    vector<TreeNode*>nodes;
    bool left;
    TreeNode*node;
    TreeNode*cur;
    public:
    It(TreeNode*root,bool l){
        node=root;
        left=l;
        next();
    }
    TreeNode* next(){
        while(node){
            //cout <<"w:"<< node->val << endl;
            nodes.push_back(node);
            node=(left ? node->left : node->right);
        }//[5,3,2]
        node = nodes.back();nodes.pop_back();//2
        cur = node;//2
        //cout << "c:" << cur->val << endl;
        node = (left ? node->right : node->left);//null   
        return cur;
    }
    TreeNode* current(){
        return cur;
    }
};
class Solution {
public:    
    bool findTarget(TreeNode* root, int k) {
        It *l=new It(root,true),*r=new It(root,false);
        while(l->current() and r->current() and l->current()->val<r->current()->val){  
            int s=l->current()->val+r->current()->val;
            //cout << s << endl;
            if(s==k)
                return true;
            if(s<k)
                l->next();
            else
                r->next();
        }
        return false;
    }
};