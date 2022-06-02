class Solution {
public:
    string s="01----9-86";
    bool isStrobogrammatic(string num) {
        string t;
        for(char c:num)
            t+=s[c-'0'];
        reverse(t.begin(),t.end());
        cout << t <<":"<<num<<endl;
        return t==num;
    }
};