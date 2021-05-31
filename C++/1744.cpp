typedef long long ll;
class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        vector<bool> res;
        ll preSum[100001]; preSum[0] = 0;
        for (int i = 1; i < candiesCount.size(); i++) {
            preSum[i] = preSum[i-1] + candiesCount[i-1];
        }

        for (auto query : queries) {
            int favoriteType = query[0], favoriteDay = query[1], dailyCap = query[2];
            int curCandyType = 0;
            //两种方式吃糖果
            //最快
            ll sumTmp = preSum[favoriteType];
            ll earliestDay = sumTmp / dailyCap;
            ll latestDay = sumTmp + candiesCount[favoriteType] - 1;
            // cout << earliestDay << " " << latestDay << endl;
            if (favoriteDay >= earliestDay && favoriteDay <= latestDay) res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};