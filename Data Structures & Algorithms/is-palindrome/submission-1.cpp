class Solution {
public:
    bool isAlphanumeric(char c) {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
    }
    bool isPalindrome(string s) {

        size_t i = 0;
        size_t j = s.size() - 1;

        while (j >= i) {
            while (!isAlphanumeric(s[i])) {
                i++;
                if (i >= s.size()) return true;
            } 
            while (!isAlphanumeric(s[j])) {
                j--;
                if (j < 0) return true;
            }
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
