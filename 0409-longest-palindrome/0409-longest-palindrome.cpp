class Solution {
public:
    int longestPalindrome(string s) {
        //counter O(N) O(N)
        vector<int> count(128);
        for(char c : s){
            count[c]++;
        }
        bool has_odd = false;
        int ans = 0;
        for(int i = 0; i < 128; i++){
            ans += count[i]/2*2;
            if(count[i]%2){
                has_odd = true;// 1
            }
        }
        return ans + has_odd;
    }
};