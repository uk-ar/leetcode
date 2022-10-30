class Solution {
public:
    long long taskSchedulerII(vector<int>& ts, int sp) {
        unordered_map<long,long>last;
        long long ans=0;
        for(auto e:ts){
            ans++;            
            if(last.count(e) and last[e]+sp+1>ans){
                ans=last[e]+sp+1;
            }
            last[e]=ans;
            //cout << e <<":"<< ans <<endl;            
        }
        return ans;
    }
};