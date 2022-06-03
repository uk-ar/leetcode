class Solution {
public:
    int maxDistToClosest(vector<int>& s) {
        int N=s.size();
        int pre=-1,ans=1;
        for(int i=0;i<N;i++){
            if(s[i]==1){
                if(pre==-1){
                    ans=i;
                }else{
                    ans=max(ans,(i-pre)/2);
                }
                pre=i;
            }
        }
        ans=max(ans,N-1-pre);
        return ans;
    }
};