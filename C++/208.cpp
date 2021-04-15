class TrieNode {
public:
    vector<TrieNode*> children;
    TrieNode() : children(26) {
        for (TrieNode* node : children) {
        node = nullptr;
        }
    }
    bool isWord = false;
};

class Trie {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode(); //注意一下指针初始化的方式
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p = root;
        for (char c : word) {
            int i = c - 'a';
            if (!p->children[i]) p->children[i] = new TrieNode();
            p = p->children[i];
        }
        p->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* p = root;
        for (char c : word) {
            int i = c - 'a';
            if (!p->children[i]) return false;
            p = p->children[i];
        }
        return p->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for (char c : prefix) {
            int i = c - 'a';
            if (!p->children[i]) return false;
            p = p->children[i];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */