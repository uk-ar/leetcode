class Solution {
public:
    int numRescueBoats(vector<int>& p, int lim) {
        sort(p.begin(),p.end());
        int N=p.size(),l=0,r=N-1,ans=0;
        while(l<=r){
            if(l==r){
                ans++;
                break;
            }
            if(p[l]+p[r]<=lim){
                l++;
                r--;
                ans++;
            }else{
                r--;
                ans++;
            }
            //cout << l << ":" << r << ":" << ans <<endl;
        }
        return ans;
    }
};