class Solution {
public:
    string addBinary(string a, string b) {
        //stack O(N) O(N)
        string st;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int i = 0, c = 0;//carry
        while(i < a.size() || i < b.size() || c){
            if(i < a.size()){
                c += a[i] - '0';
            }
            if(i < b.size()){
                c += b[i] - '0';
            }
            st.push_back((c&1) + '0');
            c >>= 1;
            i++;
        }
        reverse(st.begin(),st.end());
        return st;
    }
};