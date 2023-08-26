class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // hash set O(N) O(N)
        unordered_set<int>s(nums.begin(),nums.end());
        return s.size() != nums.size();
    }
};