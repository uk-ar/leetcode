class Solution {
public:
    int openLock(vector<string>& d, string t) {
        unordered_set<string>se(d.begin(),d.end());
        deque<string>q;
        q.push_back(t);
        int ans=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                string s=q.front();q.pop_front();
                if("0000"==s)
                    return ans;
                //cout <<ans<<":"<< s << endl;
                for(int i=0;i<4;i++){
                    string o=s;
                    s[i]=(o[i]-'0'+1)%10+'0';
                    if(!se.count(s)){
                        se.insert(s);
                        q.push_back(s);
                    }
                    s[i]=(o[i]-'0'-1+10)%10+'0';
                    if(!se.count(s)){
                        se.insert(s);
                        q.push_back(s);
                    }
                    s=o;
                }
            }
            ans++;
        }
        return -1;
    }
};