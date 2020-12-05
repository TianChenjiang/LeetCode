class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq, need;
        for (int num : nums) {
            freq[num]++;
        }
        for (int num : nums) {
            if (freq[num] == 0) { //已经被用完了
                continue;
            } else if (need[num] > 0) { // 可以加到以前的序列中
                need[num]--;
                need[num+1]++;
            } else if (freq[num+1] > 0 && freq[num+2] >0) { //可以新开一个序列 
                --freq[num+1];
                --freq[num+2];
                ++need[num+3];
            } else return false;
            --freq[num];
        }
        return true;
    }
};