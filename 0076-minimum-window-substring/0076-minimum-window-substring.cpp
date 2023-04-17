class Solution {
public:
    string minWindow(string s, string t) {
       unordered_set<char>se(t.begin(),t.end());
        unordered_map<char,int>m;
        for(char c:t)
            m[c]++;
        int l=0,r=0,N=s.size(),cnt=se.size();
        vector<int> ans={-1,-1};
        while(l<N){
            //cout << l << ":"<< r<<cnt<<endl;
            if(r<N and cnt>0){
                if(se.count(s[r]) and --m[s[r]]==0)
                    cnt--;
                r++;
            }else{
                if(se.count(s[l]) and ++m[s[l]]==1)
                    cnt++;
                l++;
            }
            if(cnt==0){
                //cout << "0:"<<l<<":"<<r<<endl;
                if(ans[0]==-1 or ans[1]-ans[0]>r-l){
                    ans={l,r};
                }
            }
        }
        if(ans[0]==-1)
            return "";
        return s.substr(ans[0],ans[1]-ans[0]);
    }
};