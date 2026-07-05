class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> charCount;
        for (const auto& ch : s) {
            charCount[ch]++;
        } 
        for (const auto& ch : t) {
            charCount[ch]--;
        }
        for (const auto& [key, value] : charCount) {
            if (value != 0) return false;
        }
        return true;
    }
};
