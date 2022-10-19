class Solution {
public:
    int M=1000000000+7;
    int countHomogenous(string s) {
        //return comb(4,2);
        long cnt=1,N=s.size(),ans=0;
        char p=s[0];
        for(int i=1;i<N;i++){
            ans=(ans+cnt)%M;
            if(p==s[i]){
                cnt++;
            }else{
                //cout << i << s[i] << cnt << ":"<<ans<<":"<<comb(cnt,2)<<endl;
                cnt=1;
                p=s[i];
            }
        }
        ans=(ans+cnt)%M;
        //cout << cnt << ":"<<ans<<":"<<comb(cnt,2)<<endl;
        return ans;
    }
};