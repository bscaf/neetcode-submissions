class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> currWindowOrder;
        vector<int> result;
        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            int currNum = nums[r];
            while (!currWindowOrder.empty() && currWindowOrder.back() < currNum) {
                currWindowOrder.pop_back();
            }
            currWindowOrder.push_back(currNum);
        
            if (r + 1 >= k) {
                result.push_back(currWindowOrder.front());
                if (nums[l] == currWindowOrder.front()) {
                currWindowOrder.pop_front();
                
                }
                l++;
            }
            
        }
        return result;
    }
}
;
