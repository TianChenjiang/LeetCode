class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int res = 0, n = people.size();
        sort(people.begin(), people.end(), greater<int>());
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            if (people[lo] + people[hi] <= limit) {
                lo++; hi--;
                res++;
            } else {
                res++;
                lo++;
            }
        }
        return res;
    }
};