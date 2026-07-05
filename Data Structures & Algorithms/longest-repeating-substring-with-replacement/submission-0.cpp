class Solution {
public:
        int characterReplacement(string s, int k) {
            unordered_map<char, int> freqMap;
            char mostFreq = s[0];
            int l{};
            int result{};
            for (int r = 0; r < s.size(); r++) {
                int windowSize = r - l + 1;
                char currChar = s[r];
                freqMap[currChar]++;
                if (freqMap[currChar] > freqMap[mostFreq]) {
                    mostFreq = currChar;
                }
                while(windowSize - freqMap[mostFreq] > k) {
                    freqMap[s[l]]--;
                    if (s[l] == mostFreq) {
                        for (auto& [key,value] : freqMap) {
                            if (value > freqMap[mostFreq]) {
                                mostFreq = key;
                            }
                        }
                    }
                    l++;
                    windowSize = r - l +1;
                }
                result = max(result, windowSize);
            }
            return result;
        }
};
