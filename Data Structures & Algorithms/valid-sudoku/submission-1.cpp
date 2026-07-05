class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        array<array<bool, 9>, 9> rowMaps{};
        array<array<bool, 9>, 9> colsMap{};
        array<array<array<bool, 9>, 3>, 3> boxMaps{};
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                char currChar = board[i][j];
                if (currChar == '.') continue;
                int currNum = currChar - '0' - 1;
                bool isInvalid = rowMaps[i][currNum] || colsMap[j][currNum] || boxMaps[i/3][j/3][currNum];
                if (isInvalid) return false;
                rowMaps[i][currNum] = true;
                colsMap[j][currNum] = true;
                boxMaps[i/3][j/3][currNum] = true;
            }
        }
        return true;
    }
};
