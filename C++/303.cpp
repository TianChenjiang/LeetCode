class NumArray {
public:
    vector<int> array;
    NumArray(vector<int>& nums) {
        array = nums;
    }
    
    int sumRange(int i, int j) {
        return accumulate(array.begin()+i, array.begin()+j+1, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */