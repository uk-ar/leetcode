class Solution {
public:
    int threeSumClosest(vector<int>& n, int t) {
        sort(n.begin(),n.end());
        int N=n.size();
        int ret=INT_MAX-10000;
        for(int i=0;i<N;i++){
            int l=i+1;
            int r=N-1;
            while(l<r){
                if(abs(ret-t)>abs(n[i]+n[l]+n[r]-t))
                    ret=n[i]+n[l]+n[r];                
                if(n[i]+n[l]+n[r]==t)
                    return t;
                else if(n[i]+n[l]+n[r]<t)
                    l++;
                else
                    r--;

                //cout << i << ":" << l << ":" << r << ":" << ret << endl;
            }
        }
        return ret;
    }
};