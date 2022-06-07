class Solution {
public:
    //using pi pair<int,string>;
    typedef pair<int,string> pi;
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>m;
        for(auto &w:words)
            m[w]++;
        //priority_queue<pi,vector<pi>,greater<pi>>q;
        priority_queue<pi>q;
        for(auto &[f,s]:m){
            q.push(make_pair(-s,f));
            if(q.size()>k)
                q.pop();
        }
        vector<string>ans;
        while(!q.empty()){
            ans.push_back(q.top().second);
            //cout << q.top().first << q.top().second <<endl;
            q.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};