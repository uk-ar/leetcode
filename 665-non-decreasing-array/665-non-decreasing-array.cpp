class Solution {
public:
    bool checkPossibility(vector<int>& n) {
        bool f=false;
        int N=n.size();
        for(int i=0;i+1<N;i++){
            if(n[i]<=n[i+1]) continue;
            if(f)
                return false;
            f=true;
            if(i==0)
                continue;
            //4,3,2
            //[3,4,2,3]
            //i. ^
            //i+1. ^
            if(n[i-1]<=n[i+1])
                n[i]=n[i+1];
            else
                n[i+1]=n[i];
        }
        return true;
    }
};