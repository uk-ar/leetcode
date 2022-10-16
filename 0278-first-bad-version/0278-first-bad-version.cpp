// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long ok=-1,ng=n;
        while(abs(ok-ng)>1){
            long m=ok+(ng-ok)/2;
            if(!isBadVersion(m)){
                ok=m;
            }else{
                ng=m;
            }
        }
        return ng;
    }
};