class Solution {
public:
    bool asteroidsDestroyed(int ma, vector<int>& as) {
        sort(as.begin(),as.end());
        int N=as.size();
        long m=ma;
        for(int i=0;i<N;i++){
            if(m>=as[i])
                m+=as[i];
            else
                return false;
        }
        return true;
    }
};