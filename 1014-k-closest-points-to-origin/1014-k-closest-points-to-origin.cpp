class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        nth_element(points.begin(),points.begin()+k,points.end(),[] (auto l, auto r){
            int d1 = l[0]*l[0] + l[1]*l[1];
            int d2 = r[0]*r[0] + r[1]*r[1];
            return d1 < d2;
        });
        return {points.begin(),points.begin()+k};
    }
};