class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& n) {
        vector<int>cnts;
        n.push_back(INT_MAX);//sentinel
        int last=1,cnt=0,N=n.size();
        for(int i=0;i<n.size();i++){
            if(n[i]==last)
                cnt++;
            else{
                cnts.push_back(cnt);
                last=n[i];
                cnt=1;
            }      
        }
        for(auto e:cnts)
            cout << e<<" ";
        cout<<endl;
        int ans=0,CN=cnts.size();
        for(int i=0;i<CN;i+=2){//check every 1
            ans=max(ans,cnts[i]);
            if(i+1<CN or i-1>=0)
                ans=max(ans,cnts[i]+1);
            if(i+1<CN){
                if(cnts[i+1]==1 and i+2<CN){
                    ans=max(ans,cnts[i]+1+cnts[i+2]);
                }else{
                    ans=max(ans,cnts[i]+1);
                }
            }
        }
        return ans;
    }
};