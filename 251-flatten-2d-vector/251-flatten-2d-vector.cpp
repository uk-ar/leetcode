class Vector2D {
public:
    //int i=0,j=0,N;
    //vector<vector<int>> vv;
    vector<vector<int>>::iterator i,ie;
    vector<int>::iterator j;
    Vector2D(vector<vector<int>>& vec) {
        i=vec.begin();
        ie=vec.end();
        if(i!=ie)
            j=i->begin();
    }
    
    int next() {
        if(!hasNext())
            return -1;
        return *j++;
    }
    
    bool hasNext() {
        while(i!=ie and j==i->end()){
            i++;
            if(i!=ie)
                j=i->begin();            
        }
        return i!=ie;
    }
};
class Vector2D_naive {
public:
    int i=0,j=0,N;
    vector<vector<int>> vv;
    Vector2D_naive(vector<vector<int>>& vec) {
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