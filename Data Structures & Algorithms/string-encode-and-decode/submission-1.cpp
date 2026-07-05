class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for (string str : strs) {
            encoded += to_string(str.size()) + '#';
            encoded += str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
       vector<string> result;
       int i = 0;
       while (i < s.size()) {
        int nextHashPos = s.find('#', i);
        int elemLength = stoi(s.substr(i, nextHashPos - i));
        i = nextHashPos + 1;
        string currString;
        while (elemLength > 0) {
            currString += s[i];
            ++i;
            --elemLength;
        }
        result.push_back(currString);
       }
       return result;
    }
};
