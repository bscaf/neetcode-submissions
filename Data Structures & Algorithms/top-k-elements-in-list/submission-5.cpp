class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }
        vector<vector<int>> freqBuckets;
        freqBuckets.resize(nums.size() + 1);

        for (const auto& [key, value] : freqMap) {
            freqBuckets[value].push_back(key);
        }

        vector<int> result;
        int missingElements = k;
        for (auto it = freqBuckets.rbegin(); it != freqBuckets.rend(); ++it) {
            vector<int> currBucket = *it;
            for (int elem : currBucket) {
                if (missingElements <= 0) break;
                result.push_back(elem);
                missingElements--;
            }
            if (missingElements <= 0) break;
        }
        return result;
    }
};
