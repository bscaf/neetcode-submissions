class Solution {
public:
    int trap(vector<int>& height) {
        int trappedWater = 0;
        vector<vector<int>> pendingBasins;
        for (int i = 0; i < height.size(); i++) {
                int currWallHeight = height[i];
                while(!pendingBasins.empty() && pendingBasins.back()[1] < currWallHeight) {
                    vector<int> info = pendingBasins.back();
                    if (currWallHeight >= info[0]) {
                        trappedWater += (info[0] - info[1])  * (i - info[2] - 1);
                        pendingBasins.pop_back();
                    } else {
                        trappedWater += (currWallHeight - info[1]) * (i - info[2] - 1);
                        pendingBasins.pop_back();
                        info[1] = currWallHeight;
                        pendingBasins.push_back(info);
                    }
                }
            if (i == height.size() - 1) continue;
            if (currWallHeight > height[i + 1]) {
                vector<int> info = {currWallHeight, height[i + 1], i};
                pendingBasins.push_back(info);
            }
        }
        return trappedWater;
    }
};
