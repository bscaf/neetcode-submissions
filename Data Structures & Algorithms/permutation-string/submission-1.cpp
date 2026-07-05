class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        unordered_map<char, int> freqMap;
        for (char c : s1) {
            freqMap[c]++;
        }
        int l {};
        unordered_map<char, int> currMap;
        for (int r = 0; r < s2.size(); r++) {
            char currChar = s2[r];
            currMap[currChar]++;
            if (!freqMap.contains(currChar)) {
                l = r + 1;
                currMap = {};
                continue;
            } 
            while (currMap[currChar] > freqMap[currChar]) {
                currMap[s2[l]]--;
                l++;
            }
            if ((r - l + 1) == s1.size()) return true;
        
            
        }
        return false;
    }
};
