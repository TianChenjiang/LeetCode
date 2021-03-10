class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int sign = 1, res = 0;
        for (int i = 0; i < s.size(); i++) {
            char chr = s[i];
            switch (chr) {
                case '+':  
                    sign = 1;
                    break;
                case '-':
                    sign = -1;
                    break;
                case '(':
                    st.push(res);
                    st.push(sign);
                    res = 0; //计算括号内值，也就是局部res
                    sign = 1;
                    break;
                case ')':
                    res *= st.top(); st.pop();
                    res += st.top(); st.pop();
                    break;
                case ' ':
                    break;
                default:
                    int num = 0;
                    while (i < s.size() && s[i] >= '0') {
                        num = 10 * num + (s[i++] - '0');
                    }
                    res += sign * num;
                    i--;
            }
        }
        return res;
    }
};