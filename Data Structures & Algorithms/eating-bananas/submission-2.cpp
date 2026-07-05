class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max{};
        for (int pile : piles) {
            max = std::max(pile, max);
        } 
        int k{INT_MAX};
        int min{1};
        while (min <= max) {
            int mid = min + (max - min) / 2;
            int totalHours{};
            for (int pile : piles) {
                totalHours += pile / mid + (pile % mid != 0);
            } 
            if (totalHours <= h && mid < k) {
                k = mid;
            }
            if (totalHours <= h) {
                max = mid - 1;
            } else {
                min = mid + 1;
            }
        }
        return k;
    }
};
