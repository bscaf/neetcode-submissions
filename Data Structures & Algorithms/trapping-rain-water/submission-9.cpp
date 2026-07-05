class Solution {
public:
    int trap(vector<int>& height) {
        int trappedWater = 0;
        // Debería haber usado un struct
        //La idea es que el primer elemento indica la altura de la torre
        //El segundo hasta que punto ya se pudo "trappear" agua, y el índice origiunal
        // para poder calcular el ancho
        vector<vector<int>> pendingBasins;
        for (int i = 0; i < height.size(); i++) {
                int currWallHeight = height[i];
                while(!pendingBasins.empty() && pendingBasins.back()[1] < currWallHeight) {
                    vector<int> basin = pendingBasins.back();
                    pendingBasins.pop_back();

                    int leftWallHeight = basin[0];
                    int filledUpTo    = basin[1];
                    int leftWallIndex = basin[2];
                    int width = i - leftWallIndex - 1;

                    if (currWallHeight >= leftWallHeight) {
                        trappedWater += (leftWallHeight - filledUpTo)  * (width);
                    } else {
                        trappedWater += (currWallHeight - filledUpTo) * (width);
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
