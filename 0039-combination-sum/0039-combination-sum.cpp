class Solution {
public:
    void backtrack(vector<int>& cand, int target, int s, vector<vector<int>>&ans,vector<int>&cur) {
        if(target <= 0){
            if(target == 0){
                ans.push_back(cur);
            }
            return;
        }
        int N = cand.size();
        for(int i = s; i < N ;i++){
            cur.push_back(cand[i]);
            backtrack(cand, target-cand[i], i, ans, cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // backtrack O(2**N)
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>cur;
        backtrack(candidates,target,0,ans,cur);
        return ans;
    }
};