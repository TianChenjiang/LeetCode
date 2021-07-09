class TimeMap {
public:
    unordered_map<string, map<int, string, greater<int>>> m;
    /** Initialize your data structure here. */
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        m[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (!m.count(key)) return "";
        for (auto mm : m[key]) {
            if (mm.first <= timestamp) return mm.second;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */