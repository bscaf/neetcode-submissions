class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lRow {};
        int rRow = matrix.size();

        // Upper bound search over the rows
        while (lRow < rRow) {
            int midRow = lRow + (rRow - lRow) / 2;
            if (matrix[midRow][0] > target) {
                rRow = midRow;
            } else {
                lRow = midRow + 1;
            }
        }

        int searchRow = (lRow == 0) ? lRow: lRow - 1;

        return binary_search(matrix[searchRow].begin(), matrix[searchRow].end(), target);
    }
};
