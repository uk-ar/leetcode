class Solution {
public:
    bool canJump(vector<int>& n) {
        int r=0,N=n.size();
        for(int i=0;i<N;i++){
            if(r<i)return false;
            r=max(r,i+n[i]);
        }
        return true;
    }
};