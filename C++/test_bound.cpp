#include <algorithm>
#include <iostream>
#include <vector>
  
int main()
{
    int unsorted[10] = { 3, 3, 2, 1, 5, 5, 4, 3, 7, 8 };
    std::vector<int> v(unsorted, unsorted + 10);
  
    // sorting vector in non increasing order. Vector
    // becomes {8, 7, 5, 5, 4, 3, 3, 3, 2, 1}
    sort(v.begin(), v.end());
    // std::sort(v.begin(), v.end(), std::greater<int>());

    std::cout << lower_bound(v.begin(), v.end(), 1) - v.begin();
  
    std::vector<int>::iterator low, up;
    low = std::lower_bound(v.begin(), v.end(), 3);         
    up = std::upper_bound(v.begin(), v.end(), 5);          
  
    std::cout << "lower_bound at position " << (low - v.begin()) << '\n';
    std::cout << "upper_bound at position " << (up - v.begin()) << '\n';
  
    return 0;
}