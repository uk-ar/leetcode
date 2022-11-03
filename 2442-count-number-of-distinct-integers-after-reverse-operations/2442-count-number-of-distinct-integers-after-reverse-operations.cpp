class Solution {
public:
    int countDistinctIntegers(vector<int>& n) {
        unordered_set<int>se;
        for(int &t:n){
            se.insert(t);
            string s=to_string(t);
            reverse(s.begin(),s.end());
            se.insert(stol(s));
        }
        /*for(auto e:se)
            cout <<e<<" ";
        cout<<endl;*/
        return se.size();
    }
};