class Solution {
public:
    int vari(string &s,char c0,char c1) {
        int r0=0,r1=0;
        for(char c:s)
            if(c0==c)
                r0++;
            else if(c1==c)
                r1++;
        int f0=0,f1=0,ans=0;
        for(char c:s){
            if(c==c0)
                f0++;
            if(c==c1){
                f1++;
                r1--;
            }
            if(f0-f1>0 and f1>0)
                ans=max(ans,f0-f1);            
            if(f0-f1<0 and r1>0){
                f0=0;
                f1=0;
            }
            //if(c0=='b' and c1=='a')
            //    cout << f0 <<":" <<f1 << ":"<<ans<<endl;
        }
        return ans;
    }
    int largestVariance(string s) {
        int ans=0;
        for(char c0='a';c0<='z';c0++){
            for(char c1='a';c1<='z';c1++){
                if(c0==c1)
                    continue;
                ans=max(ans,vari(s,c0,c1));
            }
        }
        return ans;
    }
};