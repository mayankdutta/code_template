struct Node {
    vector<Node *> next;
    bool flag;
    Node() {
        next.resize(26, nullptr); 
        flag = false;
    }
    bool contains(char ch) {
        return next[ch - 'a'] != nullptr;
    }
    Node* get(char ch) {
        return (contains(ch) ? next[ch - 'a'] : nullptr);
    }
    void put(char ch, Node *node) {
        next[ch - 'a'] = node;
    }
    void set_end() {
        flag = true;
    }
    bool is_end() {
        return flag;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        for (const auto& w: word) {
            if (!node->contains(w)) {
                node->put(w, new Node());
            }
            node = node->get(w);
        }
        node->set_end();
    }
    
    bool search(string word) {
        Node *node = root; 
        for (const auto& w: word) {
            if (!node->contains(w)) {
                return false;
            }
            node = node->get(w);
        }
        return node->is_end();
    }
    
    bool startsWith(string prefix) {
        Node *node = root; 
        for (const auto& w: prefix) {
            if (!node->contains(w)) {
                return false;
            }
            node = node->get(w);
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
