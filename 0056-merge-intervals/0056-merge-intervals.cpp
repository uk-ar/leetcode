class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort O(n log n) O(1) ex output
        sort(intervals.begin(),intervals.end());
        // add sentinel
        intervals.push_back({INT_MAX,INT_MAX});
        vector<vector<int>>ans;        
        for(int i = 0; i+1 < intervals.size(); i++){
            if(intervals[i][1] < intervals[i+1][0]){
                ans.push_back(intervals[i]);
            }else{
                intervals[i+1] = {min(intervals[i][0],intervals[i+1][0]),
                    max(intervals[i][1],intervals[i+1][1])};
            }
        }
        return ans;
    }
};