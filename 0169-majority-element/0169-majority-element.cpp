class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int N=nums.size();
        if(N<1)
            return 0;
        int cur=nums[0],count=0;
        for(int i=0;i<N;i++){
            if(cur == nums[i]){
                count++;
            }else{
                count--;
                if(count==0){
                    cur=nums[i];
                    count = 1;
                }
            }
        }
        return cur;
    }
};