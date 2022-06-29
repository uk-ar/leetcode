class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& p) {
        sort(p.begin(),p.end());
        int N=p.size();
        vector<vector<int>>ans(N);
        for(auto &v:p){
            //cout << v[0]<<":"<<v[1]<<endl;
            int j=0;
            for(int i=0;i<N;i++){
                if(ans[i].empty()){
                    if(j++==v[1])
                        ans[i]=v;
                }else if(ans[i][0]>=v[0]){
                    j++;                
                }
            }
            /*for(auto &e:ans){
                if(e.empty())
                    cout << "N ";
                else
                    cout << e[0]<<":"<<e[1]<<" ";
            }
            cout<<endl;*/
        }
        return ans;
    }
};