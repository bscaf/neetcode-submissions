class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }
        using MinPairHeap = std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>>;
        MinPairHeap heap;
        for (const auto& [key, value] : freqMap) {
            heap.push({value, key});
            if (heap.size() > k) {
                heap.pop();
            }
        }
        std::vector<int> result;
        for (; !heap.empty(); heap.pop()) {
            result.push_back(heap.top().second);
        }
        return result;
    }
};
