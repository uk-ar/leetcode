class Solution {
public:
    bool checkIfPangram(string s) {
        int b=0;
        for(auto &c:s){
            b|=1<<(c-'a');
        }
        return b==((1<<26)-1);
    }
};