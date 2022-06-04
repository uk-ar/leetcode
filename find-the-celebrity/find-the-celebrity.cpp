/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int cur=0;
        for(int i=0;i<n;i++){
            if(cur==i)continue;
            if(knows(cur,i)){
                cur=i;
            }
        }
        for(int i=0;i<n;i++){
            if(cur==i)continue;
            if(!knows(i,cur) or knows(cur,i))
                return -1;
        }
        return cur;
    }
};