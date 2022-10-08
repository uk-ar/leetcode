class Solution {
public:
    int threeSumClosest(vector<int>& nums, int t) {
        int N=nums.size(),ans=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<N-2;i++){
            int l=i+1,r=N-1;//O(n**2)     
            while(l<r){
                int s=nums[l]+nums[r]+nums[i];
                if(s==t)
                    return t;
                if(ans==INT_MAX or abs(t-ans)>abs(t-s))
                    ans=s;
                if(s<t){
                    l++;
                }else{
                    r--;
                }
            }
        }
        return ans;
    }
};