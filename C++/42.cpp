/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
         if (height.size() < 3) {return 0;}
        int maxHeight = 0;
        for (int i = 0; i < height.size(); i++) {
            maxHeight = max(maxHeight, height[i]);
        }
        int res = 0;
        for (int i = 0; i < maxHeight; i++) {
            bool first = true;
            int curIndex = 0;
            for (int j = 0; j < height.size(); j++) {
                if (height[j] >= i+1) {
                    if (first) {
                        curIndex = j;
                        first = false;
                    }
                    else {
                        res += j - curIndex - 1;
                        curIndex = j;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> v = {0,5,6,4,6,1,0,0,2,7};
    cout << s.trap(v);

}
