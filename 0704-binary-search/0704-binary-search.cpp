class Solution {
public:
    int search(vector<int>& n, int target) {
        auto it=lower_bound(n.begin(),n.end(),target);
        if(it==n.end() or target!=*it)
            return -1;
        return it-n.begin();
    }
};