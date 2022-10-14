class Solution {
public:
    int minimumRecolors(string b, int k) {
        int c=0;
        for(int i=0;i<k;i++)
            if(b[i]=='B')
                c++;
        if(c==k)
            return 0;
        int ans=k-c,n=b.size();
        for(int i=k;i<n;i++){
            c+=(b[i]=='B');
            c-=(b[i-k]=='B');
            ans=min(ans,k-c);
        }
        return ans;
    }
};