class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        vector<int> ans;
        unordered_map<int, int> freq;
        
        for (string word : words) {
            freq[getBinary(word)]++;
        }

        for (string puzzle : puzzles) {
            int total = 0;
            for (int choose = 0; choose < (1 << 6); ++choose) {
                int mask = 0;
                for (int i = 0; i < 6; ++i) {
                    if (choose & (1 << i)) {
                        mask |= (1 << (puzzle[i + 1] - 'a'));
                    }
                }
                mask |= (1 << (puzzle[0] - 'a'));
                if (freq.count(mask)) {
                    total += freq[mask];
                }
            }
            ans.push_back(total);
        }
        return ans;
    }


    int getBinary(string word) {
        int mask = 0;
        for (char chr : word) {
            mask |= 1 << (chr - 'a');
        }
        return mask;
    }
};