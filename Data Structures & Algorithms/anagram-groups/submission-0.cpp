class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        using VectorString = std::vector<std::string>;
        std::unordered_map<std::string, VectorString> anagrams;
        for (std::string str : strs) {
            std::string sorted = str;
            std::sort(sorted.begin(), sorted.end());
            if (anagrams.contains(sorted)) {
                anagrams[sorted].push_back(str);
            } else {
                anagrams[sorted] = {str};
            }
        }
        // using MapCharCount = std::unordered_map<char, int>;
        // std::unordered_map<MapCharCount, VectorString> anagrams;
        // for (std::str_view str : strs) {
        //     MapCharCount map;
        //     for (const auto& ch : str) {
        //         map[ch]++;
        //     }
        //     if (!anagram.contains(map)) {
        //         anagrams[map] = {str};
        //     } else {
        //         anagrams[map].push_back(str);
        //     }
        // }
        std::vector<VectorString> result;
        for (const auto& [key, value] : anagrams) {
            result.push_back(value);
        }
        return result;
    }
};
