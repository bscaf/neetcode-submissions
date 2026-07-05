class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;
        int r{};
        int l{};
        int result{};
        while (r < s.size()) {
            char nextChar = s[r];
            if (lastSeen[nextChar] >= l) {
                
                l = lastSeen[nextChar];
            }
            lastSeen[nextChar] = r + 1;
            result = max(result, r - l + 1);
            r++;
            
        }
        return result;
    }
};
