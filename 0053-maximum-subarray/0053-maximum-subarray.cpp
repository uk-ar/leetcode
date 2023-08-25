class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre=0,min_pre=0,ans=INT_MIN,N=nums.size();
        for(int i=0;i<N;i++){
            pre += nums[i];            
            ans = max(ans,pre - min_pre);
            min_pre = min(pre,min_pre);
        }
        return ans;
    }
};