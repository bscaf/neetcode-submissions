class Solution {
public:

    string encode(vector<string>& strs) {
        std::string encodedString {};
        encodedString += std::to_string(strs.size()) + "#";
        for (const auto& str : strs) {
            encodedString += std::to_string(str.size()) + "#" + str;
        }
        return encodedString;
    }

    vector<string> decode(string s) {
        std::string_view sv {s};
        int n = std::stoi(std::string(sv.substr(0, sv.find('#'))));
        sv = sv.substr(sv.find('#') + 1);

        std::vector<std::string> result;
        result.reserve(n);

        while (result.size() < n) {
            auto sep = sv.find('#');
            int len = std::stoi(std::string(sv.substr(0, sep)));
            sv = sv.substr(sep + 1);
            result.push_back(std::string(sv.substr(0, len)));
            sv = sv.substr(len);
        }
        return result;
    }
};
