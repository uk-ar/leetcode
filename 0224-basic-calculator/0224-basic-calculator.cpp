class Solution {
public:
    int calculate(string s) {
        int i = 0;
        string t="(";
        for(char c : s)
            if(c!=' ')
                t.push_back(c);
        t.push_back(')');
        return exp(t,i);
    }
    int digit(string &s,int &i){
        //cout << "dig" << i <<endl;
        long ans = 0;
        while(i < s.size() && isdigit(s[i])){
            ans = ans * 10 + s[i++] - '0';
        }
        return ans;        
    }
    int exp(string &s,int &i){
        //cout << "exp" << i <<endl;
        int sign = 1;
        if(s[i]=='-'){
            sign = -1;
            i++;
        }
        if(s[i]=='('){
            vector<int>v;
            i++;
            //cout << "(" <<endl;
            while(i < s.size() && s[i]!=')'){
                v.push_back(exp(s,i));
            }           
            //cout << ")" <<endl;
            i++;
            int ans = 0;
            for(auto e : v)
                ans += e;
            return sign * ans;
        }
        if(s[i]=='+')
            i++;
        return sign * digit(s,i);
    }
};