class MyCalendarTwo {
public:
    unordered_map<int,int>m;
    MyCalendarTwo() {
        
    }
    map<int,int>cnt;//imos
    bool book(int start, int end) {
        cnt[start]++;
        cnt[end]--;
        int c=0;
        for(auto &[k,v]:cnt){
            c+=v;
            if(c>=3){
                cnt[start]--;
                cnt[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */