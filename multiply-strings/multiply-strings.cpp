class Solution {
public:
    string multiply(string n1, string n2) {
        int N1=n1.size(),N2=n2.size();
        vector<int> ans(N1+N2,0);
        //"123"
        //"230"
        //0 1 2
        //  1 2 3
        //    2 3 4
        reverse(n1.begin(),n1.end());
        reverse(n2.begin(),n2.end());
        for(int i=0;i<N1;i++)
            for(int j=0;j<N2;j++){
                ans[i+j]+=(n1[i]-'0')*(n2[j]-'0');
            }
        int c=0;
        for(int i=0;i<N1+N2;i++){
            c+=ans[i];
            //cout << i<<":"<<c%10<<":"<<c/10<<endl;
            ans[i]=c%10+'0';
            c/=10;
        }
        while(ans.size()>1 and ans.back()=='0')
            ans.pop_back();
        reverse(ans.begin(),ans.end());
        return string(ans.begin(),ans.end());
    }
};