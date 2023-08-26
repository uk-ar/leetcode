class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int N = nums.size(), cur = 0, ans = INT_MIN;
        for(int e : nums){
            cur = max(cur + e, e);
            ans = max(ans, cur);
        }
        return ans;
    }
};