class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& in) {
        sort(in.begin(),in.end(),[](auto l,auto r){
            //if(l[1]==r[1])
            //    return l[0]<r[0];
            return l[1]<r[1];
        });
        int N=in.size();
        for(int i=0;i+1<N;i++){
            //cout << in[i][1] <<":"<<in[i+1][0]<<endl;
            if(in[i][1]>in[i+1][0])
                return false;
        }
        return true;
    }
};