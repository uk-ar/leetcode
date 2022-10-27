class Solution {
public:
    int findClosestNumber(vector<int>& n) {
        int ans=INT_MAX;
        for(auto e:n){
            if(abs(ans)>abs(e) or (abs(ans)==abs(e) and ans<e))
                ans=e;
        }
        return ans;
    }
};