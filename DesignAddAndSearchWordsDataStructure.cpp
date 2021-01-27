struct TrieNode {
    unordered_map<char, TrieNode*> map;
    bool word = false;
    
    TrieNode() {}
    
    TrieNode(bool word) {
        this->word = word;
    }
};

class WordDictionary {
public:
    TrieNode* root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            bool last = (i == word.size()-1);
            
            if (node->map.find(c) == node->map.end()) {
                node->map.insert({c, new TrieNode(last)});
            } else {
                if (last) node->map[c]->word = true;
            }
            
            node = node->map[c];
        }
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
    
    bool dfs(string word, int i, TrieNode* node) {
        if (i == word.size() && node->word) return true;
        
        bool ans = false;
        
        if (word[i] == '.') {
            // try all paths
            for (auto& it : node->map) {
                ans |= dfs(word, i+1, it.second);
                if (ans) break;
            }
        } else {
            // check if path exists
            if (node->map.find(word[i]) != node->map.end()) {
                ans = dfs(word, i+1, node->map[word[i]]);
            } else {
                ans = false;
            }
        }
        
        return ans;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
