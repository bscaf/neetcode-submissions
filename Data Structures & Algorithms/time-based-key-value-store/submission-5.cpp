class TimeMap {
private:
    unordered_map<string, vector<int>> timestampsPerKey;
    unordered_map<string, vector<string>> keyValues;
public:    
    void set(string key, string value, int timestamp) {
        keyValues[key].push_back(value);
        timestampsPerKey[key].push_back(timestamp);
    }
    
    string get(string key, int timestamp) { 
        if (!keyValues.contains(key)) {
            return "";
        } 
        vector<int> timestamps = timestampsPerKey[key];
        vector<string> values = keyValues[key];

        int l {0};
        int r = timestamps.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (timestamps[mid] <= timestamp) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        // Modified upper bound over timestamps
        // return values[index]

        if (l == 0) {
                return "";
        } else {
            return values[l - 1];
        }

    }
};
