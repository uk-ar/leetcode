class Solution {
public:
    long long comb(int n,int k){
        long ans=1;
        for(int i=1;i<=k;i++){
            ans=ans*(n-i+1)/i;
        }
        return ans;
    }
    long long zeroFilledSubarray(vector<int>& n) {
        long c=0,ans=0;
        for(auto e:n){
            if(e==0){
                c++;
            }else{                
                if(c>0)
                    ans+=comb(c+1,2);//3,2->6
                c=0;
            }
            //cout << e <<":"<<c<<":"<<ans<<" ";
        }
        ans+=comb(c+1,2);
        return ans;
    }
};