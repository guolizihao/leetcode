//https://leetcode.com/problems/implement-trie-prefix-tree/

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode *child[26];
    bool is_word;
    TrieNode() {
        is_word = false;
        for (auto &a : child) {
            a = NULL;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *p = root;
        for (auto a : word) { // a为引用
            int i = a - 'a';
            if (p->child[i] == NULL) p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->is_word = true; 
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *p = root;
        for (auto a : word) {
            int i = a - 'a';
            if (p->child[i] == NULL) return false;
            p = p->child[i];
        }
        return p->is_word;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for (auto a : prefix) {
            int i = a - 'a';
            if (p->child[i] == NULL) return false;
            p = p->child[i];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
