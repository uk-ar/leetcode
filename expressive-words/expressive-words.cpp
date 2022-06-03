class Solution {
public:
    void comp(string s,int lim,string &o,vector<int>&v){
        s.push_back(' ');//sentinel
        int N=s.size(),cnt=0;
        char l=0;
        for(int i=0;i<N;i++){
            if(s[i]==l)
                cnt++;
            else{
                o+=l;
                v.push_back(cnt);
                l=s[i];
                cnt=1;
            }
        }
        return;
    }
    int expressiveWords(string s, vector<string>& words) {
        string so;
        vector<int>sv;
        comp(s,2,so,sv);
        int ans=0;
        for(auto &w:words){
            string wo;
            vector<int>wv;
            comp(w,2,wo,wv);
            if(wo!=so)continue;
            int i;
            for(i=0;i<wo.size();i++){
                cout << w <<":"<<i<<":" <<sv[i]<<":"<<wv[i]<<endl;
                if(sv[i]==wv[i])continue;
                else if(sv[i]<wv[i] or sv[i]==2)
                    break;           
            }
            if(i==wo.size())
                ans++;
        }
        return ans;
    }
};