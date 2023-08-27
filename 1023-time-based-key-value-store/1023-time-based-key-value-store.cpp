class TimeMap {
public:
    // hash_map {key:[[timestamp,value]]}
    unordered_map<string,vector<pair<int,string>>>store;
    TimeMap() {
        
    }
    // O(1)
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp,value});
    }
    // O(n log n)
    // binary search for get
    string get(string key, int timestamp) {
        //pair<int,string> p = make_pair(timestamp+1,"");
        auto it = upper_bound(store[key].begin(),store[key].end(),pair<int,string>(timestamp,""),[](auto l,auto r){
            return l.first < r.first;
        });
        if(it == store[key].begin())
            return "";//not found
        it--;
        return (*it).second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */