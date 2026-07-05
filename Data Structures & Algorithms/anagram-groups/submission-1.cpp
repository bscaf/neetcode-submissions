class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        std::unordered_map<std::string, std::vector<std::string>> anagrams;
        for (std::string str : strs) {
            std::array<int, 26> charCount{};
            for (const auto& ch : str) {
                charCount[ch - 'a']++;
            }
            std::string key(charCount.begin(), charCount.end());
            anagrams[key].push_back(str);
        }
        std::vector<std::vector<std::string>> result;
        for ( auto& [key, value] : anagrams) {
            result.push_back(std::move(value));
        }
        return result;
    }
};
