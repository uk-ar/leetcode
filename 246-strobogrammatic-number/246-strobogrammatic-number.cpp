class Solution {
public:
    string s="01----9-86";
    bool isStrobogrammatic(string n) {
        int N=n.size();//,r=N-1;
        for(int i=0;i<N;i++)
            if(s[n[i]-'0']!=n[N-1-i])
                return false;        
        return true;
    }
};