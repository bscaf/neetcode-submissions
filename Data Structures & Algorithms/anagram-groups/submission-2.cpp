class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        using ComplexMap = std::unordered_map<std::string, std::vector<std::string>>;
        ComplexMap groupedAnagrams;
        for (std::string str : strs) {
            std::array<int, 26> charFreq{};
            for (char c : str) {
                charFreq[c - 'a']++;
            }
            std::string encodedArr(charFreq.begin(), charFreq.end());
            groupedAnagrams[encodedArr].push_back(str);
        }
       std::vector<std::vector<std::string>> result;
       for (const auto& [key, value] : groupedAnagrams) {
        result.push_back(value);
       }
       return result;
    }
};
