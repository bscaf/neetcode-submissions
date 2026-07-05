class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int(int, int)>> ops;
        ops["*"] = [this](int a, int b) {return a * b;};
        ops["+"] = [this](int a, int b) {return a + b;};
        ops["-"] = [this](int a, int b) {return a - b;};
        ops["/"] = [this](int a, int b) {return a / b;};

        stack<int> arguments;
        for (auto& token : tokens){
                if (ops.contains(token)) {
                    int second = arguments.top();
                    arguments.pop();
                    int first = arguments.top();
                    arguments.pop();
                    int result = ops[token](first, second);
                    arguments.push(result);
                } else {
                    arguments.push(stoi(token));
                }
                
        }
    
        return arguments.top();
    }
};
