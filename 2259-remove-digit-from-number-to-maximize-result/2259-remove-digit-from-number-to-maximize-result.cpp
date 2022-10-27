class Solution {
public:
    string removeDigit(string n, char d) {
        int N=n.size();
        string ans;
        for(int i=0;i<N;i++){
            if(n[i]==d){
                string t=n.substr(0,max(i,0))+n.substr(i+1);
                if(ans<t)
                    ans=t;
            }
        }
        return ans;
    }
};