class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int target = -nums[i];
            int r = nums.size() - 1;
            int l = i + 1;
            while (l < r) {
                int currSum = nums[l] + nums[r];
                if (currSum < target) {
                    l++;
                } else if (currSum > target) {
                    r--;
                } else {
                    result.push_back({nums[i], nums[r], nums[l]});
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                    while (l < r && nums[r] == nums[r + 1]) {
                        r--;
                    }
                }
            }
        }
        return result;
    }
};
