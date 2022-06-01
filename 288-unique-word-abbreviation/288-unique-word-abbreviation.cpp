string abbr(string &s){
    if(s.size()>2){
        int n=s.size();
        return s[0]+to_string(n-2)+s[n-1];
    }else{
        return s;
    }
}
class ValidWordAbbr {
public:
    unordered_map<string,string>m;
    ValidWordAbbr(vector<string>& d) {
        for(auto s:d){
            if(m.count(abbr(s))==0 or m[abbr(s)]==s){
                m[abbr(s)]=s;
            }else{
                m[abbr(s)]="";
            }            
        }
    }
    
    bool isUnique(string w) {
        string a=abbr(w);
        if(m.count(a)==0 or m[a]==w)
            return true;
        return false;        
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */