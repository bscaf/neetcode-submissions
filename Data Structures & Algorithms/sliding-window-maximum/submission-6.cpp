class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> currWindowOrder;
        vector<int> result;
        currWindowOrder.push_back(nums[0]);
        for (int i = 1; i < k; i++) {
            int windowMax = currWindowOrder.front();
            int windowMin = currWindowOrder.back();
            if (nums[i] > windowMax) {
                currWindowOrder = {nums[i]};
            } else {
                while (!currWindowOrder.empty() && currWindowOrder.back() < nums[i]) {
                    currWindowOrder.pop_back();
                }
                currWindowOrder.push_back(nums[i]);
            }
        }
        result.push_back(currWindowOrder.front());
        int l = 0;
        for (int r = k; r < nums.size(); r++) {
            if (nums[l] == currWindowOrder.front()) {
                currWindowOrder.pop_front();
            }
            l++;
            int currNum = nums[r];
            if (currWindowOrder.front() < currNum) {
                currWindowOrder = {currNum};
            } else {
                while (!currWindowOrder.empty() && currWindowOrder.back() < currNum) {
                    currWindowOrder.pop_back();
                }
                currWindowOrder.push_back(currNum);
            }
            result.push_back(currWindowOrder.front());
        }
        return result;
    }
};
