class Solution {
public:
    int longestPalindrome(string s) {
        
        vector<int> count(128);
        for(char c : s){
            count[c]++;
        }
        int ans = 0;
        for(int i = 0; i < 128; i++){
            ans +=count[i]/2*2;
            if(count[i]%2 && ans%2 != 1){
                ans++;
            }
        }
        return ans;
    }
};