class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       std::unordered_map<int, int> leftOverSum{};
       for (int i = 0; i < nums.size(); i++) {
        leftOverSum[target - nums[i]] = i;
       }
       for (int i = 0; i < nums.size(); i++) {
        if (leftOverSum.contains(nums[i]) && i != leftOverSum[nums[i]]) {
            return {i, leftOverSum[nums[i]]};
        }
       }
    }
};
