class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> map;
        for (int num : nums) {
            map[num]++;
        }
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> heap;
        for (const auto& [key, value] : map) {
            heap.push({value, key});
            if (heap.size() > k) {
                heap.pop();
            }
        }
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
};
