// class Solution {
// public:
//     unordered_map<int, vector<vector<int>>> m;
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         //带权最短路径
//         for (auto flight : flights) {
//             vector<int> vec({flight[1], flight[2]});
//             m[flight[0]].push_back(vec);
//         }
//         int res = INT_MAX,  curCost = 0;
//         unordered_set<int> st({src});
//         dfs(k + 1, curCost, src, dst, res, st);
//         return (res == INT_MAX) ? -1 : res;
//     }

//     void dfs(int k, int curCost, int cur, int target, int& res, unordered_set<int>& st) {
//         if (k <= 0 || curCost > res) return;
//         for (auto mm : m[cur]) {
//             if (st.count(mm[0]) || curCost + mm[1] >= res) continue;
//             if (mm[0] == target && curCost + mm[1] < res) {
//                 res = curCost + mm[1];
//                 continue;
//             }
//             st.insert(mm[0]);
//             dfs(k-1, curCost + mm[1], mm[0], target, res, st);
//             st.erase(mm[0]);
//         }
//     }
// };

