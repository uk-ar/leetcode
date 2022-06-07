class Solution {
public:
    using vi=vector<int>;
    vector<vector<int>> subsets(vector<int>& nums) {
        //bfs
        deque<vi>q={{}};
        while(!nums.empty()){
            //int n=q.size();
            int e=nums.back();nums.pop_back();
            int n=q.size();
            //for(auto v:q){
            while(n--){
                auto v=q.front();q.pop_front();
                q.push_back(v);
                v.push_back(e);
                q.push_back(v);
            }
        }
        return {q.begin(),q.end()};
    }
};