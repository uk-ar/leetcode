class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if(rec1[0]>rec2[0])
            swap(rec1,rec2);
        if(rec1[2]<=rec2[0] or rec1[3]<=rec2[1] or rec1[1]>=rec2[3])
            return false;
        return true;
    }
};