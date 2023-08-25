class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur=0,ans=INT_MIN,N=nums.size();
        for(int i=0;i<N;i++){
            cur = max(cur+nums[i],nums[i]);
            ans = max(ans,cur);
        }
        return ans;
    }
};