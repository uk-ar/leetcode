class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& n, int target) {
        int N=n.size();
        sort(n.begin(),n.end());
        vector<vector<int>>ans;
        for(int i=0;i<N;i++){
            if(i!=0 and n[i]==n[i-1])
                continue;
            for(int j=i+1;j<N;j++){
                if(j!=i+1 and n[j]==n[j-1])
                    continue;
                int l=j+1,r=N-1;
                while(l<r){
                    long s=(long)n[i]+n[j]+n[l]+n[r];
                    if(s==target){
                        ans.push_back({n[i],n[j],n[l],n[r]}); 
                        l++;r--;
                    }else if(s<target){
                        l++;
                    }else
                        r--;
                    while(l<r and l!=j+1 and n[l]==n[l-1])
                        l++;
                    while(l<r and r!=N-1 and n[r]==n[r+1])
                        r--;
                }
            }
        }
        return ans;
    }
};