string abbr(string s){
    if(s.size()>2){
        int n=s.size();
        return s[0]+to_string(n-2)+s[n-1];
    }else{
        return s;
    }
}
class ValidWordAbbr {
public:
    unordered_map<string,unordered_set<string>>m;
    ValidWordAbbr(vector<string>& d) {
        for(auto s:d){
            m[abbr(s)].emplace(s);            
        }
    }
    
    bool isUnique(string w) {
        string a=abbr(w);
        if(m.count(a)==0)
            return true;
        if(m[a].count(w) and m[a].size()<=1)
            return true;
        return false;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */