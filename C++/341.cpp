/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    int cur = 0;
    vector<NestedInteger> nestedList;
    vector<int> vec;

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        this->nestedList = nestedList;
        dfs(nestedList);
    }

    void dfs(vector<NestedInteger> nestedList) {
        for (NestedInteger nn : nestedList) {
            if (nn.isInteger()) vec.push_back(nn.getInteger());
            else dfs(nn.getList());
        }
    }
    
    int next() {
        return vec[cur++];
    }
    
    bool hasNext() {
        if (cur == vec.size()) return false;
        return true;  
    }

};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */