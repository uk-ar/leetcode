class Solution {
public:
    bool isPossible(vector<int>& t) {
        auto ma=max_element(t.begin(),t.end());
        if((*ma)==1){
            return true;
        }
        long acc=accumulate(t.begin(),t.end(),(long)0);
        //cout<< *ma << ":"<<acc<<endl;
        long d=acc-(*ma);
        if(d==1)
            return true;
        if(d==0 or d>=*ma)
            return false;
        //cout << d <<":"<< acc << ":"<<t.size()<<endl;
        //(*ma)=(*ma)%(d);
        if(*ma<=d)
            false;
        (*ma)=(*ma)%(d);
        cout << d <<":"<< acc << ":"<<(*ma)<<endl;
        /*for(auto e:t)
            cout << e <<" ";
        cout<<endl;*/
        if((*ma)<=0)
            return false;
        return isPossible(t);
    }
};