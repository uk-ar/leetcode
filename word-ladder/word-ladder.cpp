class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& words) {
        unordered_set<string>ws(words.begin(),words.end());
        if(ws.count(ew)==0)
            return 0;
        int ans=1;
        deque<string>q;
        q.push_back(bw);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                string s=q.front();q.pop_front();
                if(s==ew)
                    return ans;                
                for(int i=0;i<s.size();i++){
                    for(char c='a';c<='z';c++){
                        if(s[i]==c)continue;
                        char ori=s[i];
                        s[i]=c;
                        if(ws.count(s)){
                            q.push_back(s);                            
                            ws.erase(s);
                        }
                        s[i]=ori;
                    }                        
                }
            }
            ans++;
        }
        return 0;
    }
};