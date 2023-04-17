class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        h.push_back(0);
        int N=h.size(),ans=0;
        vector<vector<int>>st;
        for(int i=0;i<N;i++){
            vector<int>can={i,h[i]};
            while(st.size()>0 and st.back()[1]>=h[i]){
                int j=st.back()[0],t=st.back()[1];st.pop_back();
                ans=max(ans,(i-j)*t);
                can[0]=j;
            }
            st.push_back(can);
        }
        return ans;
    }
};