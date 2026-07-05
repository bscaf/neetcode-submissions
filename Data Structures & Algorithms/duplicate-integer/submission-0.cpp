class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> hashSet;
        for (int num : nums) {
            if (hashSet.contains(num)) {
                return true;
            }
            hashSet.insert(num);
        }
        return false;
    }
};