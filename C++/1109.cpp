class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n);
        for (int i = 0; i < bookings.size(); i++) {
            vector<int> b = bookings[i];
            res[b[0] - 1] += b[2];
            if (b[1] < n) res[b[1]] -= b[2];
        }
        for (int i = 1; i < n; i++) {
            res[i] += res[i-1];
        }
        return res;
    }
};