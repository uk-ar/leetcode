class Solution {
public:
    bool isPossible(vector<int>& t) {
        priority_queue<int>q(t.begin(),t.end());
        long sum=accumulate(t.begin(),t.end(),(long)0);
        while(q.top()>0){
            if(q.top()==1)
                return true;
            int n=q.top();q.pop();            
            long d=sum-n;
            //cout <<"0:"<< n <<":"<<d<<":"<<sum<<endl;
            if(d==0 or n<=d)
                return false;
            if(d==1)
                return true;
            int nex=n%d;
            if(nex==0)
                return false;
            q.push(nex);
            sum=sum-(n-nex);
            //cout <<"1:"<< n <<":"<<d<<":"<<sum<<endl;
        }        
        return false;
    }
};