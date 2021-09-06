const int ALPHABET_SIZE = 26;

struct TrieNode
{
    vector<TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        children = vector<TrieNode*>(ALPHABET_SIZE, nullptr);
        isEndOfWord = false;
    }
};

class StreamChecker {
// trie storing words in reverse order
// search from recent letter to oldest letter in stream
public:
    void insert(struct TrieNode* root, string key) {
        struct TrieNode* cur = root;
 
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (!cur->children[index])
                cur->children[index] = new TrieNode();

            cur = cur->children[index];
        }

        // mark last node as leaf
        cur->isEndOfWord = true;
    }

    bool search(struct TrieNode* root, string key) {
        struct TrieNode* cur = root;

        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (cur->isEndOfWord)
                return true;
            
            if (!cur->children[index])
                return false;

            cur = cur->children[index];
        }

        return (cur->isEndOfWord);
    }
    
    TrieNode* root;
    string buffer;
    
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        
        for (string word : words) {
            reverse(word.begin(), word.end());
            insert(root, word);
        }
        
        buffer = "";
    }
    
    bool query(char letter) {
        buffer = letter + buffer;
        if (buffer.size() > 2000) buffer = buffer.substr(0, 2000);
        return search(root, buffer);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
