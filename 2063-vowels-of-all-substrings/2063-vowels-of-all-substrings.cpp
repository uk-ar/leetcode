class Solution {
public:
    long long countVowels(string w) {
        long N=w.size(),ans=0;
        string s="aiueo";
        unordered_set<char>se(s.begin(),s.end());
        vector<long>a(N+1);
        for(int i=0;i<N;i++){
            a[i+1]=a[i];
            if(se.count(w[i]))
                a[i+1]+=(i+1);
            ans+=a[i+1];
            //cout << w[i] <<":"<< a[i+1] << endl;
        }
        return ans;
    }
};