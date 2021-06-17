class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n-1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] >= arr[r]) {
                r--;
            } else {
                l++;
            }
        }
        return l;
    }
};