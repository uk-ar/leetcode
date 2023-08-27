class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ok = 0, N = nums.size(), ng = N;
        //. [1,2,0]
        //ok     ^
        //m.       ^
        //ng       ^
        while(abs(ok-ng)>1){
            int m = (ok+ng)/2;
            cout << ok << ":"<<m<<":"<<ng<<endl;
            if((nums[ok] < nums[m] && (target <  nums[ok] || nums[m] <= target)) ||
               (nums[ok] > nums[m] && (target >= nums[m]  && target < nums[ok]))){ //second half
                   ok = m;
            }else{
                ng = m;
            }
            //0123456
            //4567012
            //.  ^^^
        }
        cout << ok <<endl;
        if(nums[ok] == target)
            return ok;
        return -1;
    }
};