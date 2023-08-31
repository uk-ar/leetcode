class Solution {
public:
    int N;
    bool cousume(string &s,int &i,char c){
        if(s[i] == c){
            i++;
            return true;
        }
        return false;
    }
    int exp(string &s,int &i){
        int acc = mul(s,i);
        while(i<N){
            if(cousume(s,i,'+')){
                acc += mul(s,i);
            }else if(cousume(s,i,'-')){
                acc -= mul(s,i);
            }else{
                return acc;
            }
        }
        return acc;
    }
    int mul(string &s,int &i){
        int acc = primary(s,i);
        while(i<N){
            if(cousume(s,i,'*')){
                acc *= primary(s,i);
            }else if(cousume(s,i,'/')){
                acc /= primary(s,i);
            }else{
                return acc;
            }
        }
        return acc;
    }
    int primary(string &s,int &i){
        if(cousume(s,i,'(')){
            int ans = exp(s,i);
            i++;//skip ')'
            return ans;
        }
        int ans = 0;
        while(i < N && isdigit(s[i])){
            ans = ans * 10 - '0' + s[i++] ;
        }
        return ans;
    }
    
    int calculate(string s0) {
        int i = 0;
        string s;
        for(char c : s0)
            if(c != ' ')
                s += c;
        N = s.size();
        return exp(s,i);
    }
};