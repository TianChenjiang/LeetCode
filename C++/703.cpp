class KthLargest {
public:
    int k = 0;
    vector<int> vec;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->vec = nums;
        sort(this->vec.begin(), this->vec.end());
    }
    
    int add(int val) {
        int n = vec.size();
        if (n == 0 || val >= vec[n-1]) vec.push_back(val);
        else {
            for (auto it = vec.begin(); it != vec.end(); it++) {
                if (val < *it) {
                    vec.insert(it, val);
                    break;
                }
            } 
        }
        return vec[n + 1 - this->k];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */