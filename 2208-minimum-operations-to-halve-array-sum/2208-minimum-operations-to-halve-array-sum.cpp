class Solution {
public:
    int halveArray(vector<int>& n) {
        double s=0;
        priority_queue<double>q(n.begin(),n.end());
        for(auto e:n)
            s+=e;            
        double h=s/2;
        //cout << h<<":"<<s<<endl;
        int ans=0;
        while(h>0){
            double t=q.top();q.pop();
            h-=t/2;
            q.push(t/2);
            ans++;
        }
        return ans;
    }
};