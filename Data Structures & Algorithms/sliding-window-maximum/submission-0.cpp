class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> numbersSeen;
        unordered_map<int, int> currWindowFreq;
        for (int i = 0; i < k; i++) {
            numbersSeen.push(nums[i]);
            currWindowFreq[nums[i]]++;
        }
        vector<int> result;
        result.push_back(numbersSeen.top());
        int l = 0;
        for (int r = k; r < nums.size(); r++) {
            currWindowFreq[nums[l]]--;
            if (numbersSeen.top() == nums[l]) {
                numbersSeen.pop();
            }
            l++;
            currWindowFreq[nums[r]]++;
            numbersSeen.push(nums[r]);
            while (currWindowFreq[numbersSeen.top()] == 0) {
                numbersSeen.pop();
            }
            result.push_back(numbersSeen.top());
        }
        return result;
    }
};
