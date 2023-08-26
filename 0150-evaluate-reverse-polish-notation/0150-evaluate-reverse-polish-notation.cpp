class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // stack O(N) O(N)
        vector<int>st;
        for(string token : tokens){
            if(st.empty() || isdigit(token.back())){
                st.push_back(stoi(token));
            }else{
                int b = st.back();st.pop_back();
                int a = st.back();st.pop_back();
                if(token == "+"){
                    st.push_back(a+b);
                }else if(token == "-"){
                    st.push_back(a-b);
                }else if(token == "/"){
                    st.push_back(a/b);
                }else if(token == "*"){
                    st.push_back(a*b);
                }
            }
        }
        return st[0];
    }
};