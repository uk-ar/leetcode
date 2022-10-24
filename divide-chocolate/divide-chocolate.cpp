class Solution {
public:
    int cut(vector<int>& sw, int m) {
        int c=0,ans=0;//m=min sweet
        for(auto e:sw){
            c+=e;
            if(c>=m){
                c=0;
                ans++;
            }
        }
        //if(c>0)
        //            ans--;
        return ans;
    }
    int maximizeSweetness(vector<int>& sw, int k) {
        /*int ma=INT_MIN;
        for(auto e:sw)
            ma=max(e,ma);*/
        int ok=1,ng=INT_MAX;
        while(abs(ng-ok)>1){
            int m=ok+(ng-ok)/2;
            //cout << m <<":"<<cut(sw,m)<<endl;
            if(cut(sw,m)>=k+1){
                ok=m;
            }else{
                ng=m;
            }
        }
        //cout<<endl;
        return ok;
    }
};