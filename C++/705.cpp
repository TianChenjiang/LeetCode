class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<list<int>> vec;
    const static int base = 769;
    static int hash(int key) {
        return key % base;
    }
    MyHashSet() : vec(base) {}
    
    void add(int key) {
        int hashKey = hash(key);
        for (auto it = vec[hashKey].begin(); it != vec[hashKey].end(); it++) {
            if (*it == key) return;
        }
        vec[hashKey].push_back(key);
    }
    
    void remove(int key) {
        int hashKey = hash(key);
        for (auto it = vec[hashKey].begin(); it != vec[hashKey].end(); it++) {
            if (*it == key) {
                vec[hashKey].erase(it); 
                return;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int hashKey = hash(key);
        for (auto it = vec[hashKey].begin(); it != vec[hashKey].end(); it++) {
            if (*it == key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */