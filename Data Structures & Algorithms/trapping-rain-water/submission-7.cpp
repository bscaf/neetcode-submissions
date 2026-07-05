class Solution {
public:
    int trap(vector<int>& height) {
        int trappedWater = 0;
        vector<vector<int>> pendingBasins;
        for (int i = 0; i < height.size(); i++) {
                int currWallHeight = height[i];
                while(!pendingBasins.empty() && pendingBasins.back()[1] < currWallHeight) {
                    vector<int> basin = pendingBasins.back();
                    int leftWallHeight = basin[0];
                    int fillFrom    = basin[1];
                    int leftWallIndex = basin[2];
                    int width = i - leftWallIndex - 1;

                    if (currWallHeight >= leftWallHeight) {
                        trappedWater += (leftWallHeight - fillFrom)  * (width);
                        pendingBasins.pop_back();
                    } else {
                        trappedWater += (currWallHeight - fillFrom) * (width);
                        pendingBasins.pop_back();
                        basin[1] = currWallHeight;
                        pendingBasins.push_back(basin);
                    }
                }
            if (i == height.size() - 1) continue;
            if (currWallHeight > height[i + 1]) {
                vector<int> basin = {currWallHeight, height[i + 1], i};
                pendingBasins.push_back(basin);
            }
        }
        return trappedWater;
    }
};
