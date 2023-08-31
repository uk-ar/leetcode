class Solution {
public:
    int N;
    bool consume(string &s, int &i, char c) {
        if(s[i]==c){
            i++;
            return true;
        }
        return false;
    }
    int exp(string &s, int &i) {
        int acc = mul(s,i);
        while(i < N){
            if(consume(s,i,'+')){
                acc += mul(s,i);
            }else if(consume(s,i,'-')){
                acc -= mul(s,i);
            }else{
                break;
            }
        }
        return acc;
    }
    int mul(string &s, int &i) {
        int acc = primary(s,i);
        while(i < N){
            if(consume(s,i,'*')){
                acc *= primary(s,i);
            }else if(consume(s,i,'/')){
                acc /= primary(s,i);
            }else{
                break;
            }
        }
        return acc;
    }
    int primary(string &s, int &i) {        
        int ans = 0;
        if(consume(s,i,'(')){
            ans = exp(s,i);
            i++;//skip ')'
            return ans;
        }
        while(i < N && isdigit(s[i])){
            ans = ans*10 - '0' + s[i++];
        }
        return ans;
    }
    int calculate(string s0) {
        string s;
        for(char c : s0)
            if(c!=' ')
                s += c;
        N = s.size();
        int i = 0;
        return exp(s,i);
    }
};