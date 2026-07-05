class Solution {
public:
    bool meetBeforeTarget(float target, pair<int, int>& left, const pair<int, int>& right) {
        if (left.second <= right.second) return false;
        float timeToMeet = static_cast<float>(right.first - left.first) / (left.second - right.second);
        return timeToMeet <= (target - right.first) / right.second;
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<pair<int, int>> carFleetsLeft;
        vector<pair<int, int>> sorted;
        for (int i = 0; i < position.size(); i++) {
            sorted.push_back({position[i], speed[i]});
        }
        sort(sorted.begin(), sorted.end(), less<pair<int, int>>());
        for (int i = 0; i < sorted.size(); i++) {
            if (carFleetsLeft.empty()) {
                carFleetsLeft.push(sorted[i]);
                continue;
            }
            while (!carFleetsLeft.empty() && meetBeforeTarget(target, carFleetsLeft.top(), sorted[i])) {
                carFleetsLeft.pop();
            }
            carFleetsLeft.push(sorted[i]);
        }
        return carFleetsLeft.size();
    }
};
