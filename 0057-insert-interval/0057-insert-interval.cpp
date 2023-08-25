class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        intervals.push_back({INT_MAX,INT_MAX});
        vector<int>in = newInterval;
        for(auto v:intervals){
            if(v[1]<in[0]){
                ans.push_back(v);
            }else if(in[1]<v[0]){
                ans.push_back(in);
                in = v;
            }else{
                in={min(in[0],v[0]),max(in[1],v[1])};
            }
        }
        return ans;
    }
};