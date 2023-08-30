class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& ins, vector<int>& newIn) {
        ins.push_back({INT_MAX,INT_MAX});
        int N = ins.size();
        vector<vector<int>>ans;
        for(auto in : ins){
            if(newIn[1] < in[0]){
                ans.push_back(newIn);
                newIn = in;
            }else if(in[1] < newIn[0]){
                ans.push_back(in);
            }
            else{
                newIn = {min(in[0],newIn[0]),max(in[1],newIn[1])};
            }
            cout << newIn[0] <<":" << newIn[1] <<endl;
        }
        return ans;
    }
};