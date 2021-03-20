class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int res = 0, cnt = 1;
        stack<string> st;
        for (string str : tokens) {
            if (str ==  "+" || str == "-" || str == "*" || str == "/") {
                int b = stoi(st.top()); st.pop();
                int a = stoi(st.top()); st.pop();
                if (str == "+") st.push(to_string(a+b));
                if (str == "-") st.push(to_string(a-b));
                if (str == "*") st.push(to_string(a*b));
                if (str == "/") st.push(to_string(a/b));
            } else {
                st.push(str);
            }
        }
        return stoi(st.top());
    }
};