class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res = "";
        vector<string> strs;
        for (int num : nums) {
            strs.push_back(to_string(num));
        }
        sort(strs.begin(), strs.end(), [] (string &a, string &b)  {
            return a + b < b + a;
        });
        for (int i = strs.size()-1; i >= 0; i--) {
            res += strs[i];
        }
        return res[0] == '0' ? "0" : res;
    }
};