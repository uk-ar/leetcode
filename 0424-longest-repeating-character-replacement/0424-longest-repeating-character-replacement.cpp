class Solution {
public:
    pair<int,int> max_elem(vector<int>&v){//other,sum
        int m=0,s=0;
        for(char c='A';c<='Z';c++){
            //if(v[c])
            //    cout << c << v[c]<<endl;
            m=max(m,v[c]);
            s+=v[c];
        }
        return {s-m,s};
    }
    int characterReplacement(string s, int k) {
        int r=0,l=0,n=s.size(),ans=0;
        vector<int>v(128);
        while(l<n){
            auto p=max_elem(v);
            //cout <<l <<":"<< r <<":"<< p.first<<":"<<p.second<<endl;
            if(r<n and p.first<=k){//A    
                //cout << "a"<<s[r]<<endl;
                v[s[r]]++;                
                r++;
                p=max_elem(v);
                if(p.first<=k)
                    ans=max(ans,p.second);
            }else{                
                //cout << "b"<<endl;
                v[s[l]]--;
                l++;
            }
        }
        //cout<<endl;
        return ans;
    }
};