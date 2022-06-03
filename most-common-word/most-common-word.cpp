class Solution {
public:
    string cannonical(string s){
        int N=s.size();
        string t;
        for(int i=0;i<N;i++)
            if(isalpha(s[i]))
                t+=tolower(s[i]);
        return t;
    }
    string mostCommonWord(string p, vector<string>& b) {    
        unordered_map<string,int>m;
        unordered_set<string>ban(b.begin(),b.end());
        //while(ss>>word){
        p.push_back('.');//sentinel
        string word,ans;
        int N=p.size();
        for(int i=0;i<N;i++){
            if(isalpha(p[i])){
                word+=tolower(p[i]);
            }else{
                if(word=="")continue;
                string t=word;//=cannonical(word);
                if(ban.count(t)==0 and ++m[t]>m[ans]){
                    ans=t;
                }
                word.clear();
            }
        }
        return ans;
    }
};