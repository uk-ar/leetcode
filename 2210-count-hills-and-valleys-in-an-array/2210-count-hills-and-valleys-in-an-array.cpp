class Solution {
public:
    int countHillValley(vector<int>& n) {
        int N=n.size();
        int d=0,ans=0,cnt=0;
        for(int i=0;i+1<N;i++){
            if(n[i]<n[i+1]){
                if(d<0)
                    ans++;
                d=1;
            }else if(n[i]>n[i+1]){
                if(d>0)
                    ans++;
                d=-1;
            }else{                
            }         
        }
        return ans;
    }
};