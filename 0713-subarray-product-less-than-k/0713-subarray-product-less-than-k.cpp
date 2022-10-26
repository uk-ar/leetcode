class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& n, int k) {
        int r=0,N=n.size(),c=1,ans=0,l=0;
        for(int r=0;r<N;r++){
            c*=n[r];
            while(l<=r and k<=c)
                c/=n[l++];
            ans+=r-l+1;
            //cout << l << ":" << r <<":" <<c << ":" << ans<<endl;
        }
        return ans;
    }
    int _numSubarrayProductLessThanK(vector<int>& n, int k) {
        int l=0,r=0,c=1,N=n.size(),ans=0;
        while(l<N){
            if(c<k){
                ans+=r-l;
            }
            cout << l << ":" <<r<<":"<<c<<":"<<ans<<endl;
            if(r==l or (r<N and c<k)){
                c*=n[r];
                r++;
            }else{
                c/=n[l];
                l++;
            }
        }
        return ans;
    }
};