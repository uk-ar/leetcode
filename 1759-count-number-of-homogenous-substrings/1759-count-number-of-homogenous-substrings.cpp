class Solution {
public:
    int M=1000000000+7;
    int comb(int n,int k){
        long ans=1;
        for(int i=0;i<k;i++){//2/1*1/2 3/1*2/2*1/3
            ans=(ans*(n-i))%M;
            ans=(ans/(i+1))%M;
        }
        return ans;
    }
    int countHomogenous(string s) {
        //return comb(4,2);
        long cnt=1,N=s.size(),ans=0;
        char p=s[0];
        for(int i=1;i<N;i++){
            if(p==s[i]){
                cnt++;
            }else{
                ans=(ans+comb(cnt+1,2))%M;
                //cout << i << s[i] << cnt << ":"<<ans<<":"<<comb(cnt,2)<<endl;
                cnt=1;
                p=s[i];
            }
        }
        ans=(ans+comb(cnt+1,2))%M;
        //cout << cnt << ":"<<ans<<":"<<comb(cnt,2)<<endl;
        return ans;
    }
};