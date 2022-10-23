class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& a, int k) {
        unordered_map<int,int>freq;//e,cnt
        map<int,unordered_set<int>>ind;//freq,ind
        int N=a.size();
        for(int i=0;i<N;i++){
            ind[freq[a[i]]].erase(a[i]);//1,5
            freq[a[i]]++;
            ind[freq[a[i]]].insert(a[i]);
        }
        for(auto &[f,v]:ind){            
            for(auto e:v){                
                int act=min(f,k);
                k-=act;
                //cout << f <<":"<<e<<":"<<k<<endl;
                freq[e]-=act;
            }
        }
        int ans=0;
        for(auto &[e,c]:freq){
            if(c>0){
                //cout << e << ":" << c<<endl;
                ans++;
            }
        }
        return ans;
    }
};