class Solution {
public:
    int trap(vector<int>& height) {
        int maxWaterArea = 0;
        vector<vector<int>> stack;
        for (int i = 0; i < height.size(); i++) {
                while(!stack.empty() && stack.back()[1] < height[i]) {
                    vector<int> info = stack.back();
                    if (height[i] >= info[0]) {
                        maxWaterArea += (info[0] - info[1])  * (i - info[2] - 1);
                        stack.pop_back();
                    } else {
                        maxWaterArea += (height[i] - info[1]) * (i - info[2] - 1);
                        stack.pop_back();
                        info[1] = height[i];
                        stack.push_back(info);
                    }
                }
            if (i == height.size() - 1) continue;
            if (height[i] > height[i + 1]) {
                vector<int> info = {height[i], height[i + 1], i};
                stack.push_back(info);
            }
        }
        return maxWaterArea;
    }
};
