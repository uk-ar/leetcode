class Solution {
public:
    int largestCombination(vector<int>& can) {
        int ans=0;
        for(int i=0;i<32;i++){
            int t=0;
            for(auto e:can){
                if(e&(1<<i))
                    t++;
            }
            ans=max(ans,t);
        }
        return ans;
    }
};