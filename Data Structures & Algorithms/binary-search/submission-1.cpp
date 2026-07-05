class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l {};
        int r {};
        r = nums.size() - 1;
        int mid{};
        mid = (r - l) / 2;

        while (r != l) {
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                if (mid == nums.size() - 1) return -1;
                l = mid + 1;
            } else {
                if (mid == 0) return -1;
                r = mid - 1;
            }
                mid = l + (r - l) / 2;
        }
        if (nums[r] == target) return r;
        return -1;
    }
};
