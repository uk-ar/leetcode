class Solution {
public:
    int search(vector<int>& n, int t) {
        int ok=0,N=n.size(),ng=N;
        while(abs(ok-ng)>1){
            int m=ok+(ng-ok)/2;
            /*cout << ok <<":"<<m<<":"<<ng<<endl;
            cout << (n[ok]<n[m] and (n[ok]<=t and t<n[m])) <<endl;
            cout << (n[ok]>n[m] and (n[ok]<=t or  t<n[m])) <<endl;*/
            if((n[ok]<n[m] and (n[ok]<=t and t<n[m])) or
               (n[ok]>n[m] and (n[ok]<=t or  t<n[m]))){
                ng=m;
            }else{
                ok=m;
            }
            
        }
        if(n[ok]==t)
            return ok;
        return -1;
    }
};