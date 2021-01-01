class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;
        int nn = flowerbed.size();
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        for (int i = 1; i <= nn; i++) {
            if (flowerbed[i] != 1 && flowerbed[i-1] != 1 && flowerbed[i+1] != 1) {
                n--;
                if (n == 0) break;
                flowerbed[i] = 1;
            }
        }
        return n == 0 ? true : false;
    }
};
