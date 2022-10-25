class Solution {
public:
    bool backtrack(int i,string num,vector<int> &ans){
        /*for(auto e:ans)
            cout << e <<" ";
        cout << ":" << i <<endl;*/
        if(i==num.size() and ans.size()>=3)
            return true;
        if(i>=num.size())
            return false;//?
        int n=ans.size();//[0,1,1]
        if((long)ans[n-1]+ans[n-2]>INT_MAX)
            return false;
        string t=to_string(ans[n-1]+ans[n-2]);
        for(int j=0;j<t.size();j++){
            if(num[i+j]!=t[j])
                return false;
        }
        ans.push_back(ans[n-1]+ans[n-2]);
        if(backtrack(i+t.size(),num,ans))
            return true;
        ans.pop_back();
        return false;
    }
    vector<int> splitIntoFibonacci(string num) {
        int N=num.size();        
        for(int i=1;i<=min(11,(N+2)/3);i++){
            vector<int> ans;
            string t=num.substr(0,i);
            if(t.size()!=1 and t[0]=='0')
                continue;
            if(stol(t)>INT_MAX)
                continue;
            ans.push_back(stoi(t));            
            for(int j=1;j<=min(11,(N+2)/3);j++){                             
                string t=num.substr(i,j);
                if(t.size()!=1 and t[0]=='0')
                    continue;
                if(stol(t)>INT_MAX)
                    continue;
                ans.push_back(stoi(t));
                if(backtrack(i+j,num,ans))
                    return ans;
                ans.pop_back();
            }
        }
        return {};
    }
};