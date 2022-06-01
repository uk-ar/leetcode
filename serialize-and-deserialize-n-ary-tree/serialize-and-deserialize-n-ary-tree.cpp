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

class Codec {
public:
    // Encodes a tree to a single string.
    string dfs(Node* root) {
        string ans;
        if(!root)
            return ans;
        ans+=to_string(root->val)+" ";
        if(root->children.empty())
            return ans;
        ans+="[";
        for(auto e:root->children)
            ans+=dfs(e);
        ans+="]";
        return ans;
    }
    string serialize(Node* root) {
        return dfs(root);
    }
	int N;
    Node* dfs(string d,int &i){
        //cout << i << endl;
        int n=0;
        //[2 3 [6 7 [11 [14 ]]]
        while(i<N and isdigit(d[i])){
            n=n*10+d[i]-'0';
            i++;
        }
        while(i<N and d[i]==' ') i++;
        Node*ans=new Node(n);
        if(d[i]!='[')
            return ans;
        i++;//skip [
        for(;i<d.size() and d[i]!=']';){
            ans->children.push_back(dfs(d,i));
        }
        i++;//skip ]
        return ans;
    }
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if(data=="")
            return nullptr;
        N=data.size();
        cout << data << endl;
        int i=0;
        return dfs(data,i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));