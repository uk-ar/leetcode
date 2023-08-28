class Solution {
public:
    void sortColors(vector<int>& nums) {
        int N = nums.size(), z = 0,t = N;
        for(int i = 0; i < t ; i++){
            while(i < t && nums[i] == 2){
                swap(nums[--t],nums[i]);
            }
            if(nums[i] == 0){
                swap(nums[i],nums[z++]);
            }
        }
        return;
    }
};