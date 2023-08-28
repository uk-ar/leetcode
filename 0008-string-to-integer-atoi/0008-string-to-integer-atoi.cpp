class Solution {
public:
    int skipblank(string &s,int i){
        while(i < s.size() && s[i] == ' ')
            i++;
        return i;
    }
    int myAtoi(string s) {
        int sign = 1, i = 0;
        i = skipblank(s,i);
        if(s[i] == '-'){
            sign = -1;
            i++;
        }else if(s[i] == '+'){
            i++;
        }
        int ans = 0;
        while(i < s.size() && isdigit(s[i])){
            if(ans > (INT_MAX - s[i] + '0')/10){
                if(sign == 1)
                    return INT_MAX;
                return INT_MIN;
            }                
            ans = ans * 10 - '0' + s[i++];
        }
        return sign * ans;
    }
};