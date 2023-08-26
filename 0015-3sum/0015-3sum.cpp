class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int N = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i = 0; i < N ; i++){
            if(i != 0 && nums[i] == nums[i-1]){
                continue;
            }
            int l = i+1, r = N-1;
            while(l < r){
                int s = nums[i]+nums[l]+nums[r];
                if(s == 0){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    while(l+1<r && nums[l] == nums[l+1])
                        l++;
                    l++;
                    r--;
                }else if(s < 0){
                    l++;
                }else{
                    r--;
                }
            }
        }
        return ans;
    }
};