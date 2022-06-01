class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& n) {
        //sliding window
        vector<int>c(2,0);
        int N=n.size(),l=0,ans=0;
        for(int r=0;r<N;r++){
            c[n[r]]++;
            while(l<r and c[0]>1){
                c[n[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};