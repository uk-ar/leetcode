class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) {
        int ok=0,N=a.size(),ng=N;
        //  [0,2,1,0]
        //ng 
        //ok
        while(abs(ok-ng)>1){
            int m=(ok+ng)/2;
            if(a[m-1]<a[m])
                ok=m;
            else
                ng=m;
        }
        return ok;
    }
};