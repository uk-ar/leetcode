class Solution {
public:
    int shortestDistance(vector<string>& ws, string w1, string w2) {
        int N=ws.size(),i1=-1,i2=-1,ans=INT_MAX;
        for(int i=0;i<N;i++){
            if(ws[i]==w1){
                i1=i;
                if(i2!=-1)
                    ans=min(ans,i1-i2);
            }else if(ws[i]==w2){
                i2=i;
                if(i1!=-1)
                    ans=min(ans,i2-i1);
            }
            cout << i1 <<":"<< i2 <<":"<<ans <<endl;
        }
        return ans;
    }
};