class Solution {
public:
    int calculate(string s) {
        int res = 0, sign = 1, n = s.size(), num = 0, tmp = 0, top = 0;
        stack<int> st;
        char preOpt = '+';
        for (int i = 0; i < n; i++) {
            char chr = s[i];
            if (chr >= '0') {
                while (i < n && s[i] >= '0') {
                        num = num * 10  - '0' + s[i++];
                }
                i--;
            }
            if (i == n-1 || chr == '+' || chr == '-' || chr == '*' || chr == '/') {
                switch (preOpt) {
                    case '+' : 
                        st.push(num);
                        break;
                    case '-' : 
                        st.push(-num);
                        break;
                    case '*' : 
                        top = st.top();
                        st.pop();
                        st.push(top * num);
                        break;
                    case '/' :
                        top = st.top();
                        st.pop();
                        st.push(top / num);
                        break;
                }
                num = 0;
                preOpt = chr;
            } 
        }
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};