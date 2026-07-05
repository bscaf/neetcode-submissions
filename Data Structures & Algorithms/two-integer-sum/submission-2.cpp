class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> result;
        std::unordered_map<int, int> partialResults;

        for (int i = 0; i < nums.size(); ++i) {
            int partialResult = target - nums[i];
            if (!partialResults.contains(nums[i])) {
                partialResults[partialResult] = i;
            } else {
                result.push_back(partialResults[nums[i]]);
                result.push_back(i);
                return result;
            }
            
        }
    }
};
