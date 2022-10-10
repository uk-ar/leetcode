class Solution {
public:
    string breakPalindrome(string p) {
        int N=p.size();
        if(N==1)
            return "";
        bool odd=N%2;
        for(int i=0;i<N;i++){
            if(i==N/2 and odd)
                continue;
            if(p[i]!='a'){
                p[i]='a';
                return p;
            }
        }
        p[N-1]='b';
        return p;
        //aaaa->aaab
        //aa->ab        
        
    }
};