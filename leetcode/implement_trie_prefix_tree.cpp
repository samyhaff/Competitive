class Trie {
private:
    unordered_map<char, Trie *> children;
    bool isEndOfWord;

public:
    Trie() {
       children = unordered_map<char, Trie *>();
       isEndOfWord = false;
    }

    void insert(string word) {
        Trie *current = this;
        for (auto c: word) {
            if (current->children.find(c) == current->children.end()) {
                Trie *new_trie = new Trie();
                current->children[c] = new_trie;
            }
            current = current->children[c];
        }
        current->isEndOfWord = true;
    }

    bool search(string word) {
        Trie *current = this;
        char c;
        for (auto c : word) {
            if (current->children.find(c) == current->children.end())
                return false;
            current = current->children[c];
        }
        return current->isEndOfWord;
    }

    bool startsWith(string prefix) {
        Trie *current = this;
        for (char c: prefix) {
            if (current->children.find(c) == current->children.end())
                return false;
            current = current->children[c];
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
