class Solution {
public:
    vector<int> partitionLabels(string s) {
        int N=s.size();
        vector<int>last(128);
        for(int i=0;i<N;i++)
            last[s[i]]=i;
        int st=0,end=0;
        vector<int>ans;
        // ababcbacadefegdehijhklij
        //s^
        //i        ^
        //e        ^
        for(int i=0;i<N;i++){
            end=max(end,last[s[i]]);
            if(end==i){
                ans.push_back(i-st+1);
                st=i+1;
            }                
        }
        return ans;
    }
};