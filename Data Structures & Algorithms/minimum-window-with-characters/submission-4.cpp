class Solution {
public:
    string minWindow(string s, string t) {

        unordered_set<char> seta(t.begin(), t.end());
        unordered_map<char, int> freqMap;
        unordered_map<char, int> currWindowFreqMap;
        for (char c : t) {
            freqMap[c]++;
        }
        int matches{};
        string result = "";
        int l{};
        for (int r = 0; r < s.size(); r++) {
            int index = s[r];
            currWindowFreqMap[index]++;
            if (freqMap[index] > 0) {
                if (currWindowFreqMap[index] == freqMap[index]) {
                    matches++;
                }
            }
            if (matches == seta.size()) {
                int leftIndex = s[l];
                int leftFreq = currWindowFreqMap[leftIndex];
                while(leftFreq - 1 >= freqMap[leftIndex]) {
                    currWindowFreqMap[leftIndex]--;
                    l++;
                    leftIndex = s[l];
                    leftFreq = currWindowFreqMap[leftIndex];
                }
                if (result.size() > (r - l + 1) || result == "") {
                    result = s.substr(l, r - l + 1);
                }
                
                leftIndex = s[l];
                currWindowFreqMap[leftIndex]--;
                leftFreq = currWindowFreqMap[leftIndex];
                if (leftFreq < freqMap[leftIndex]) {
                    matches--;
                }
                l++;
            }
        }

        return result;
    }
};
