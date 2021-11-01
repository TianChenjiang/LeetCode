bool cmp(pair<int,int>&p1, pair<int,int>&p2) {
        return p1.second < p2.second;
}
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> st;
        for (int ct : candyType) st.insert(ct);
        return min(candyType.size() / 2, st.size());
    }
};