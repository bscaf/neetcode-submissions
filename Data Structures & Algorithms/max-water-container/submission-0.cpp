class Solution {
public:
    int maxArea(vector<int>& heights) {
        int longestBase = heights.size() - 1;
        int currMaxArea = min(heights[0],heights[longestBase]) * longestBase;
        int r = longestBase;
        int l = 0;
        while(l < r) {
            int leftHeight = heights[l];
            int rightHeight = heights[r];
            int currArea = min(leftHeight, rightHeight) * (r - l);
            if (currArea > currMaxArea) {
                currMaxArea = currArea;
            }
            if (leftHeight < rightHeight) {
                l++;
            } else {
                r--;
            }
        }

        return currMaxArea;
    }
};
