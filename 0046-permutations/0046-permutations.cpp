class Solution {
public:
    void backtrack(vector<int>& nums, int i, vector<vector<int>>&ans) {
        int N = nums.size();
        if(i >= N){
            ans.push_back(nums);
            return;
        }
        for(int j = i; j < N; j++){
            swap(nums[i],nums[j]);
            backtrack(nums,i+1,ans);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        //backtrack O(n!) O(n!)
        vector<vector<int>>ans;
        backtrack(nums,0,ans);
        return ans;
    }
};