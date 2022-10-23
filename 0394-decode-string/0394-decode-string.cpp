class Solution {
public:
    int N;
    int strtol(string s,int &i){
        int ans=0;
        while(i<N and isdigit(s[i])){
            ans=ans*10+s[i++]-'0';
        }
        return ans;
    }
    string stos(string s,int &i){
        string t;
        if(s[i]=='[')
            i++;
        while(i<N and s[i]!=']'){
            if(isdigit(s[i])){
                int j = strtol(s,i);
                string u=stos(s,i);
                for(int k=0;k<j;k++){
                    t+=u;
                }
            }else if(s[i]!='['){
                t+=s[i];
            }else{// if(s[i]=='['){
                t+=stos(s,i);
            }
            i++;
        }
        return t;
    }
    string decodeString(string s) {
        int i=0;
        N=s.size();
        string t;
        /*while(i<N){
            int j = strtol(s,i);
            string u=stos(s,i);
            for(int k=0;k<j;k++){
                t+=u;
            }
            i++;
        }*/
        return stos(s,i);
    }
};