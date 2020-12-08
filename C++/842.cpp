class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> res, out;
        helper(S, 0, res, out);
        return res;
    }

    void helper(string S, int start, vector<int>& res, vector<int> &out) {
        if (!res.empty()) return; //结束递归
        if (start >= S.size() && out.size() >= 3) { //满足返回的结果
            res = out;
            return;
        }
        for (int i = start; i < S.size(); i++) {
            string cur = S.substr(start, i-start+1);
            if (cur.size() > 1 && cur[0] == '0' || cur.size() > 10) break;
            long num = stol(cur), len = out.size();
            if (num > INT_MAX) break;
            if (len >= 2 && num != (long)out[len-1] + out[len-2]) { //大于两个，且不满足
                continue;
            }
            out.push_back(num); //out小于两个，可以直接放进out里面
            helper(S, i+1, res, out);
            out.pop_back(); // 恢复out状态
        }
    }

};