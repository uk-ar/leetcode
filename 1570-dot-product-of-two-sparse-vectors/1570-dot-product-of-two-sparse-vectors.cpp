class SparseVector {
public:
    vector<pair<int,int>>m1;
    SparseVector(vector<int> &n) {
        int N=n.size();
        for(int i=0;i<N;i++)
            if(n[i]!=0){
                m1.push_back({i,n[i]});
            }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int i1=0,i2=0,ans=0;
        vector<pair<int,int>>&m2=vec.m1;
        while(i1<m1.size() and i2<m2.size()){
            if(m1[i1].first==m2[i2].first){
                ans+=m1[i1].second*m2[i2].second;
                i1++;i2++;
            }else if(m1[i1].first<m2[i2].first){
                i1++;
            }else{
                i2++;
            }
        }
        return ans;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);