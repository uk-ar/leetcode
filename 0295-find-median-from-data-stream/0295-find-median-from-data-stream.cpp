class MedianFinder {
public:
    priority_queue<int>q_max;
    priority_queue<int,vector<int>,greater<int>>q_min;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        q_max.push(num);
        q_min.push(q_max.top());q_max.pop();
        if(q_min.size()>q_max.size()){
            q_max.push(q_min.top());q_min.pop();
        }
    }
    
    double findMedian() {
        if(q_max.size()==q_min.size())
            return (q_min.top()+q_max.top())/2.0;
        return q_max.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */