//https://leetcode.com/problems/add-and-search-word-data-structure-design/

class WordDictionary {
public:
    struct TrieNode {
        TrieNode *child[26];
        bool is_word;
        TrieNode() {
            is_word = false;
            for (auto &a : child) {
                a = NULL;
            }
        }
    };
    
    WordDictionary() {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *p = root;
        for (auto &a : word) {
            int i = a - 'a';
            if (p->child[i] == NULL) p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->is_word = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return SearchWordDFS(word, root, 0);
    }
    
    bool SearchWordDFS(string &word, TrieNode *p, int i) {
        if (i == word.size()) return p->is_word;
        if (word[i] == '.') {
            for (auto &a : p->child) {
                if (a != NULL && SearchWordDFS(word, a, i + 1)) return true;
            }
            return false;
        } else {
            return p->child[word[i] - 'a'] && SearchWordDFS(word, p->child[word[i] - 'a'], i + 1);
        }
    }
    
private: 
    TrieNode *root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
