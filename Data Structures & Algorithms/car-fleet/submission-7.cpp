class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<float> arrivalTimes;
        vector<pair<int, int>> sorted;
        for (int i = 0; i < position.size(); i++) {
            sorted.push_back({position[i], speed[i]});
        }
        sort(sorted.begin(), sorted.end(), less<pair<int, int>>());

        for (int i = 0; i < sorted.size(); i++) {
            float arrivalTime = static_cast<float>(target - sorted[i].first) / sorted[i].second;
            if (arrivalTimes.empty()) {
                arrivalTimes.push(arrivalTime);
                continue;
            }
            while (!arrivalTimes.empty() && arrivalTimes.top() <= arrivalTime) {
                arrivalTimes.pop();
            }
            arrivalTimes.push(arrivalTime);
        }
        return arrivalTimes.size();
    }
};
