class Solution {
public:
    int longestSubarray(vector<int>& n, int lim) {
        int l=0,r=1,N=n.size(),ans=0;
        deque<pair<int,int>>max_e,min_e;
        max_e.push_back({0,n[0]});
        min_e.push_back({0,n[0]});
        while(l<N){
            int ma=max_e.front().second,mi=min_e.front().second;  
            if(ma-mi<=lim)
                ans=max(ans,r-l);
            if(r<N and ma-mi<=lim){
                while(!max_e.empty() and max_e.back().second<n[r])
                    max_e.pop_back();
                max_e.push_back({r,n[r]});
                while(!min_e.empty() and min_e.back().second>n[r])
                    min_e.pop_back();
                min_e.push_back({r,n[r]});
                r++;
            }else{
                if(max_e.front().first<=l)
                    max_e.pop_front();
                if(min_e.front().first<=l)
                    min_e.pop_front();
                l++;
            }
        }
        return ans;
    }
};