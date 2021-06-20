class ThroneInheritance {
private:
    string king;
    unordered_map<string, vector<string>> family;
    unordered_set<string> dead;
    void preorder(string parentName, vector<string>& res) {
        if (!dead.count(parentName)) res.push_back(parentName);
        for (string n : family[parentName]) {
            preorder(n, res);
        }
    }

public:
    ThroneInheritance(string kingName) {
        king = kingName;
    }
    
    void birth(string parentName, string childName) {
        family[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> res;
        preorder(king, res);
        return res;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */