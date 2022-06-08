class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    map<int,int>cnt;
    int book(int start, int end) {
        cnt[start]++;
        cnt[end]--;
        int t=0,ans=0;
        for(auto &[k,v]:cnt){
            t+=v;
            ans=max(ans,t);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */