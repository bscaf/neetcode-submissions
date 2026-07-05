class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> prevTemps;
        vector<int> result(temperatures.size());
        for (int i = 0; i < temperatures.size(); i++) {
            while (!prevTemps.empty() && prevTemps.top().first < temperatures[i]){
                int prevTempIndex = prevTemps.top().second;
                prevTemps.pop();
                result[prevTempIndex] = i - prevTempIndex;
            }
            prevTemps.push({temperatures[i], i});
        }
        return result;
    }
};
