class Solution {
public:
    int countHillValley(vector<int>& n) {
        int pre=0,N=n.size(),ans=0;
        for(int i=0;i+1<N;i++){
            if((n[pre]<n[i] and n[i]>n[i+1]) or
               (n[pre]>n[i] and n[i]<n[i+1])){
                ans++;
                pre=i;
            }                
        }
        return ans;
    }
};