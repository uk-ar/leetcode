class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& bs) {
        map<int,vector<int>>cnt;
        for(auto &b:bs){
            cnt[b[0]].push_back(b[2]);
            cnt[b[1]].push_back(-b[2]);
        }
        map<int,int>t;
        int c=0;
        vector<vector<int>>ans;
        for(auto &[k,v]:cnt){               
            int b=c;
            for(auto &e:v){
                if(e>0)
                    t[e]++;
                else{
                    if(--t[-e]==0)
                        t.erase(-e);
                }
            }
            //for(auto e:t)
                //cout << e.first <<":"<< e.second <<" ";
            //cout<<":"<< k<<endl;
            if(t.empty())
                c=0;
            else{
                //cout << (*t.rbegin()).first <<":"<< (*t.rbegin()).second <<endl;
                c=(*t.rbegin()).first;
            }
            //cout <<"cb:"<< c <<":"<<b<<endl;
            if(c!=b)
                ans.push_back({k,c});
        }
        return ans;
    }
};