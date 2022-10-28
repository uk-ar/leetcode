class Solution {
public:
    long long subArrayRanges(vector<int>& n) {
        int N=n.size();
        vector<long>l(N),st,r(N);
        for(int i=0;i<=N;i++){
            while(!st.empty() and (i==N or n[st.back()]>n[i])){
                l[st.back()]=i-st.back();
                st.pop_back();
            }
            st.push_back(i);
        }
        st.clear();
        for(int i=N-1;i>=-1;i--){
            while(!st.empty() and (i==-1 or n[st.back()]>=n[i])){
                r[st.back()]=st.back()-i;
                st.pop_back();
            }
            st.push_back(i);
        }
        st.clear();
        long ans=0;
        for(int i=0;i<N;i++){       
            //cout << n[i] <<":" << l[i] <<":" << r[i] << endl;
            ans-=(long)n[i]*l[i]*r[i];
        }
        for(int i=0;i<=N;i++){
            while(!st.empty() and (i==N or n[st.back()]<n[i])){
                l[st.back()]=i-st.back();
                st.pop_back();
            }
            st.push_back(i);
        }
        st.clear();
        for(int i=N-1;i>=-1;i--){
            while(!st.empty() and (i==-1 or n[st.back()]<=n[i])){
                r[st.back()]=st.back()-i;
                st.pop_back();
            }
            st.push_back(i);
        }
        st.clear();
        for(int i=0;i<N;i++){ 
            //cout << n[i] <<":" << l[i] <<":" << r[i] << endl;
            ans+=(long)n[i]*l[i]*r[i];
        }
        return ans;
    }
};