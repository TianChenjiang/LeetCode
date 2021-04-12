#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> nums = {1,2,3,4,5};
    int target = 4;
    int l = 0, r = nums.size();
    while (l < r) {
        int mid = (l + r) >> 1;
        if (target < nums[mid]) {
            r = mid;
        } else if (target > nums[mid]){
            l = mid + 1;
        } else cout << mid;
    }
}