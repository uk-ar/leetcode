class Solution {
public:
    int totalFruit(vector<int>& f) {
        //f.push_back(-1);//sentinel
        int N=f.size(),ans=INT_MIN,l=0;
        unordered_map<int,int>m;
        for(int r=0;r<N;r++){
            m[f[r]]++;
            while(l<r and m.size()>2){
                if(--m[f[l]]==0)
                    m.erase(f[l]);
                l++;
            }
            /*for(auto &[k,v]:m)
                cout << k<<":"<<v<<" ";
            cout<<endl;
            cout<<l<<":"<<r<<endl;*/
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};