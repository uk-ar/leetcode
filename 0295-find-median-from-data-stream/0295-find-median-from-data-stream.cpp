class MedianFinder {
public:
    priority_queue<int>ma;//low//[2]
    priority_queue<int,vector<int>,greater<int>>mi;//high
    MedianFinder() {
        
    }
    
    void addNum(int n) {
        ma.push(n);//[1]
        mi.push(ma.top());
        ma.pop();
        if(mi.size()>ma.size()){
            ma.push(mi.top());
            mi.pop();
        }
    }
    
    double findMedian() {
        if(ma.size()==mi.size())
            return (ma.top()+mi.top())/2.0;
        return ma.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */