class Solution {
public:
    int minimumOperations(vector<int>& n) {
        vector<int>v(101);
        int cnt=0;
        for(int e:n)        
            if(++v[e]==1 and e!=0)
                cnt++;
        return cnt;
    }
};