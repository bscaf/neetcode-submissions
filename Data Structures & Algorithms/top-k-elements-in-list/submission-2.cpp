class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> freqMap;
        std::vector<int> result;
        for (int num : nums) {
            freqMap[num]++;
        }
        vector<vector<int>> freqBucket(nums.size() + 1);
        for (const auto& [key, value] : freqMap) {
            freqBucket[value].push_back(key);
        }
        for (auto it = freqBucket.rbegin(); k > 0 && it != freqBucket.rend(); it++) {
            for (int num : *it) {
                result.push_back(num);
                k--;
            }
        }
        return result;
    }
};
