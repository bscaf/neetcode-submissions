class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {
            int result = numbers[left] + numbers[right];
            if (result > target) {
                right--;
            } else if (result < target) {
                left++;
            } else {
                return {left + 1, right + 1};
            }
        }
    }
};
