class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, l = 0, r = 0 ,N = s.size();
        vector<int>count(128);
        while(l < N){
            if(r < N && count[s[r]] == 0){                
                count[s[r]]++;
                r++;
                ans = max(ans,r-l);
            }else{
                count[s[l]]--;
                l++;
            }
        }
        return ans;
    }
};