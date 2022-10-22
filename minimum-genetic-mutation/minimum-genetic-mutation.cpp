class Solution {
public:
    int next(string t,string bb){
        int n=t.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(t[i]!=bb[i])
                ans++;
        }
        return ans;
    }
    int minMutation(string s, string e, vector<string>& ba) {
        unordered_set<string>b(ba.begin(),ba.end());
        if(b.count(e)==0 or s.size()!=e.size())
            return -1;
        deque<string>q;
        q.push_back(s);
        int ans=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                string t=q.front();q.pop_front();
                b.erase(t);
                if(t==e)
                    return ans;
                for(auto bb:b){
                    if(next(t,bb)!=1)
                        continue;
                    cout << t <<"->" <<bb<<endl;
                    q.push_back(bb);
                }
            }
            ans++;
        }
        return -1;
    }
};