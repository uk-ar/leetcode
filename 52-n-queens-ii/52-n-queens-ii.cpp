class Solution {
public:
    int backtrack(int i,int col,int add,int sub,int N){
        if(i==N){
            return 1;
        }
        int ans=0;
        for(int j=0;j<N;j++){
            if(((col>>j)&1)==1)
                continue;
            if(((add>>(i+j))&1)==1)
                continue;
            if(((sub>>(i-j+8))&1)==1)
                continue;
            ans+=backtrack(i+1,col|(1<<j),add|(1<<(i+j)),sub|(1<<(i-j+8)),N);
        }
        return ans;
    }
    int totalNQueens(int n) {
        return backtrack(0,0,0,0,n);
    }
};