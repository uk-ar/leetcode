class Vector2D {
public:
    int i=0,j=0,N;
    vector<vector<int>> vv;
    Vector2D(vector<vector<int>>& vec) {
        vv=vec;
        N=vec.size();
    }
    
    int next() {
        if(!hasNext())
            return -1;
        return vv[i][j++];
    }
    
    bool hasNext() {
        while(i<N and j>=vv[i].size()){
            j=0;
            i++;
        }
        return i<N;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */