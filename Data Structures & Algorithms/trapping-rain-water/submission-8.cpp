class Solution {
public:
    int trap(vector<int>& height) {
        int trappedWater = 0;
        vector<vector<int>> pendingBasins;
        for (int i = 0; i < height.size(); i++) {
                int currWallHeight = height[i];
                while(!pendingBasins.empty() && pendingBasins.back()[1] < currWallHeight) {
                    vector<int> basin = pendingBasins.back();
                    pendingBasins.pop_back();

                    int leftWallHeight = basin[0];
                    int fillFrom    = basin[1];
                    int leftWallIndex = basin[2];
                    int width = i - leftWallIndex - 1;

                    if (currWallHeight >= leftWallHeight) {
                        trappedWater += (leftWallHeight - fillFrom)  * (width);
                    } else {
                        trappedWater += (currWallHeight - fillFrom) * (width);
                        basin[1] = currWallHeight;
                        pendingBasins.push_back(basin);
                    }
                }
            if (i < height.size() - 1 && currWallHeight > height[i + 1]) {
                vector<int> basin = {currWallHeight, height[i + 1], i};
                pendingBasins.push_back(basin);
            }
        }
        return trappedWater;
    }
};
