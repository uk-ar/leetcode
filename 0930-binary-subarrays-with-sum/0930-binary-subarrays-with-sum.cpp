class Solution {
public:
    int numSubarraysWithSum(vector<int>& n, int g) {
        vector<int>v;     
        int c=0;
        for(int i=0;i<n.size();i++){
            if(n[i]==0){
                c++;
            }else if(i!=0 and n[i-1]!=n[i]){//0->1
                v.push_back(c);
                c=0;
                v.push_back(1);
            }else{
                v.push_back(0);
                v.push_back(1);
            }
        }
        //if(n.back()==1)
        v.push_back(c);//end with 0
        /*for(auto e:v){
            cout << e << " ";
        }*/
        //0123456
        //0111110
        //^   ^
        //  ^   ^
        //cout<<endl;
        int ans=0;
        for(int i=0;i+g*2<v.size();i+=2){
            if(g==0){
                ans+=v[i]*(v[i]+1)/2;
            }else{
                ans+=(v[i]+1)*(v[i+g*2]+1);
            }
        }
        return ans;
    }
};