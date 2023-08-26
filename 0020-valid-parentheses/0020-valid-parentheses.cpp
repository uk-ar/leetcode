class Solution {
public:
    bool isValid(string s) {
        // stack O(N) O(N)
        string st;
        unordered_map<char,char>pairs({{')','('},{'}','{'},{']','['}});
        for(char c : s){
            if(pairs.count(c)){
                if(st.empty() || st.back() != pairs[c]){
                    return false;
                }
                st.pop_back();
            }else{
                st.push_back(c);
            }
        }
        return st.empty();
    }
};