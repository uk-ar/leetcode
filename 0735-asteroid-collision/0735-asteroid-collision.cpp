class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int>ans;
        for(auto e:a){
            while(e!=0){
                if(ans.empty() or (ans.back()<0==e<0)){
                    ans.push_back(e);
                    break;
                }else if(e<0 and ans.back()>0){
                    if(ans.back()==abs(e)){
                        ans.pop_back();
                        break;
                    }else if(ans.back()<abs(e)){
                        ans.pop_back();
                    }else if(ans.back()>abs(e)){
                        e=0;
                    }
                }else{
                    ans.push_back(e);
                    break;
                }
            }
        }
        return ans;
    }
};