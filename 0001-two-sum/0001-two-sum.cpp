class Solution {
public:
    vector<int> twoSum(vector<int>& n, int t) {
        unordered_map<int,int>m;
        int N=n.size();
        for(int i=0;i<N;i++){
            if(m.count(t-n[i]))
                return {m[t-n[i]],i};
            m[n[i]]=i;
        }
        return {-1,-1};
    }
};