class Solution {
public:
    int maxNumberOfBalloons(string text) {        
        string t="balon";
        unordered_set<char>s({t.begin(),t.end()});
        unordered_map<int,int>m;
        for(char &c:text)
            if(s.count(c))
                m[c]++;
        int ans=INT_MAX;
        for(auto &c:"balon"){
            if(c=='l' or c=='o'){
                ans=min(ans,m[c]/2);
            }else if(c!=0){
                ans=min(ans,m[c]);
            }
        }
        return ans;
    }
};