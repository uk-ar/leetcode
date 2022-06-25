class Solution {
public:
    int singleNumber(vector<int>& n) {
        int x=0;
        for(auto e:n)
            x^=e;
        return x;
    }
};