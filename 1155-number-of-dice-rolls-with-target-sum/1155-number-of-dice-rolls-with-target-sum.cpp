class Solution {
public:
    int M=1000000000+7;
    unordered_map<int,unordered_map<int,int>>m;
    int numRollsToTarget(int n, int k, int target) {
        if(n==0 and target==0)
            return 1;
        if(n*k<target or n>target)
            return 0;
        if(m[n].count(target))
            return m[n][target];
        long long t=0;
        for(int i=1;i<=k;i++){
            t=(numRollsToTarget(n-1,k,target-i)+t)%M;
        }
        return m[n][target]=t%M;
    }
};