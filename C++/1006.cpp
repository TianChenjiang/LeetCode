class Solution {
public:
    int clumsy(int N) {
        stack<int> st;
        int res = 0, cnt = 0;
        st.push(N);
        for (int i = N-1; i > 0; i--, cnt++) {
            if (cnt % 4 == 2) st.push(i);
            else if (cnt % 4 == 3) st.push(-i);
            else if (cnt % 4 == 0) {
                int t = st.top(); st.pop();
                st.push(t * i);
            }
            else if (cnt % 4 == 1) {
                int t = st.top(); st.pop();
                st.push(t / i);
            }
        }
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};