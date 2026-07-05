class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numsSet(nums.begin(), nums.end());
        int result = 0;
        for (int num : nums) {
            if (!numsSet.contains(num - 1)) {
                int currNum = num;
                int length = 0;
                while (numsSet.contains(currNum)) {
                    currNum++;
                    length++;
                }
                if (length > result) result = length;
            }
        }
        return result;
    }
};
