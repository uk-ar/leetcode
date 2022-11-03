class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int t) {
        int H=m.size(),W=m[0].size();
        int ok=-1,ng=H*W;
        while(abs(ok-ng)>1){
            int mid=ok+(ng-ok)/2;
            if(m[mid/W][mid%W]==t)
                return true;
            if(m[mid/W][mid%W]<t){
                ok=mid;
            }else{
                ng=mid;
            }
        }
        return false;
    }
};