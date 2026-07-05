class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> leftProduct(size);
        vector<int> rightProduct(size);
        for (int i = 0; i < size; i++) {
            if (i == 0) {
                leftProduct[i] = 1;
                rightProduct[size - 1 - i] = 1;
            } else {
                leftProduct[i] = leftProduct[i - 1] * nums[i - 1];
                rightProduct[size - 1 -i] = rightProduct[size - i] * nums[size - i];
            }
        }

        vector<int> result(size);
        for (int i = 0; i < size; i++) {
            result[i] = leftProduct[i] * rightProduct[i];
        }
        return result;
    }
};
