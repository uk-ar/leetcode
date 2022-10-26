class Solution {
public:
    int longestContinuousSubstring(string s) {
        int N=s.size(),c=1,ans=1;
        for(int i=0;i+1<N;i++){
            if(s[i]+1==s[i+1]){
                c++;
            }else{
                c=1;
            }            
            ans=max(ans,c);
            //cout << i << s[i] << ans <<endl;
        }
        return ans;
    }
};