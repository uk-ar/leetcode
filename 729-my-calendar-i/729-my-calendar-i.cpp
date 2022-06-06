class MyCalendar {
public:
    MyCalendar() {
        
    }
    map<int,int>en;//{end:st}
    bool book(int start, int end) {
        auto l=en.lower_bound(end);
        if(l!=en.end() and (*l).second<end)
            return false;
        auto u=en.upper_bound(end);
        if(u!=en.begin() and start<(*--u).first)
            return false;
        en[end]=start;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */