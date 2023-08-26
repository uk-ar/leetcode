class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums[0], count = 0;
        for(int e : nums){
            if(e == majority){
                count++;
            }else{
                if(count == 0){
                    count++;
                    majority = e;
                }else{
                    count--;
                }
            }
        }
        return majority;
    }
};