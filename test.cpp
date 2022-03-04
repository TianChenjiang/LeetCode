#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int getAnswer() {

}

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
    priority_queue<int, vector<int>, less<int>> pq;
    unordered_map<int, int> m;
}