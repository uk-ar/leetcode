class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int>v(128);
        int cnt=0;
        for(char &c:sentence){
            if(++v[c]==1)
                cnt++;
        }
        return cnt==26;
    }
};