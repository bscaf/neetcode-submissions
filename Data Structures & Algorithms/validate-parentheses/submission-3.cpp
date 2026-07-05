class Solution {
public:
    bool isValid(string s) {
        stack<char> opening;
        int i = 0;
        for (char c : s) {
            switch (c) {
                case '(':
                case '{':
                case '[':
                    opening.push(c);
                    break;
                case ')':
                    if (opening.empty() || opening.top() != '(') return false;
                    opening.pop();
                    break;
                case '}':
                    if (opening.empty() || opening.top() != '{') return false;
                    opening.pop();
                    break;
                case ']':
                    if (opening.empty() || opening.top() != '[') return false;
                    opening.pop();
                    break;
                default:
                    break;
            }
        }
        if (opening.size() > 0) return false;
        return true;

    }
};
