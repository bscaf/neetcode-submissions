class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> topKHeap;
        for (const auto& [key, value] : freqMap) {
            topKHeap.push({value, key});
            if (topKHeap.size() > k) topKHeap.pop();
        }

        vector<int> result;
        for (int i = 0; i < k; ++i) {
            const auto& [freq, num] = topKHeap.top();
            result.push_back(num);
            topKHeap.pop();
        }
        return result;
    }
};
