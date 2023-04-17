class Solution {
public:
    int N;
    void white(string &s,int &i){
        while(i<N and s[i]==' ')
            i++;
    }
    int digit(string &s,int &i){
        int ans=0;
        while(i<N and isdigit(s[i])){            
            ans=ans*10-'0'+s[i];
            i++;
        }
        return ans;
    }
    int exp(string &s,int &i){
        vector<int>st;
        int sign=1;
        int ans=0;
        while(i<N){
            white(s,i);
            if(s[i]=='('){
                i++;
                st.push_back(sign*exp(s,i));
                sign=1;
            }else if(s[i]==')'){
                i++;
                for(auto e:st)
                    ans+=e;
                return sign*ans;
            }else if(s[i]=='-'){
                i++;
                sign=-1;
            }else if(s[i]=='+'){
                i++;
            }else{
                st.push_back(sign*digit(s,i));
                sign=1;
            }
        }
        for(auto e:st){
            //cout<<e<<" ";
            ans+=e;
        }
        //cout<<endl;
        return sign*ans;
    }
    int calculate(string s) {
        N=s.size();
        int i=0;
        return exp(s,i);
    }
};