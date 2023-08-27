class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //     [1,2,3]
        //lr   [1,1,2,6]
        //rl [6,6,3,1]
        int N=nums.size();
        vector<int>lr(N+1,1),rl(N+1,1);
        for(int i = 0; i < N ; i++){
            lr[i+1]=lr[i]*nums[i];
        }
        for(int i = N-1; i >=0 ; i--){
            rl[i]=rl[i+1]*nums[i];
        }
        vector<int>ans(N);
        for(int i = 0; i < N ; i++){
            ans[i]=lr[i]*rl[i+1];
        }
        return ans;
    }
};