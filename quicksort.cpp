#include<iostream>
#include<vector>
using namespace std;

void quickSort(vector<int>& arr, int l, int r) {
    if (r <= l) return;
    int i = l, j = r;
    while (i < j) {
        int piovt = arr[l]; //选择最左边的元素作为哨兵
        while (i < j && arr[i] < piovt) i++; //找到第一个不满足左半部分小于哨兵元素的数
        while (i < j && arr[j] > piovt) j--; //找到第一个不满足右半部分大于哨兵元素的数
        swap(arr[i], arr[j]);
    }
    swap(arr[l], arr[i]);
    quickSort(arr, l, i - 1);
    quickSort(arr, i + 1, r);
}

int main() {
    vector<int> arr = {9,8,7,10,5};
    quickSort(arr, 0, arr.size() - 1);
    for (int a : arr) cout << a << " ";
}