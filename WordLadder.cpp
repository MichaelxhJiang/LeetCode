class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // create graph that maps generic transforms to words in wordList
        // BFS from beginWord to endWord
        
        // build graph
        unordered_map<string, vector<string>> adjList; // generic transform -> matchings words in wordList
        for (int i = 0; i < wordList.size(); i++) {
            // generate all generic word transformations
            for (int j = 0; j < wordList[i].size(); j++) {
                string generic = wordList[i].substr(0, j) + "*" + wordList[i].substr(j+1);
                if (adjList.find(generic) == adjList.end()) {
                    adjList[generic] = vector<string>();
                }
                adjList[generic].push_back(wordList[i]);
            }
        }
        
        // BFS traversal
        int ans = 0;
        queue<pair<string, int>> q; // <node index, distance>
        unordered_set<string> visited;
        
        q.push(make_pair(beginWord, 1)); // start at beginWord (last element in list)
        visited.insert(beginWord);
        
        while (!q.empty()) {
            pair<string, int> node = q.front(); q.pop();
            string word = node.first;
            
            if (word == endWord) {
                ans = node.second;
                break;
            }
            
            for (int i = 0; i < word.size(); i++) {
                string generic = word.substr(0, i) + "*" + word.substr(i+1);
                if (adjList.find(generic) == adjList.end()) continue;
                
                for (string next : adjList[generic]) {
                    if (visited.find(next) != visited.end()) continue;
                    q.push(make_pair(next, node.second+1));
                    visited.insert(next);
                }
            }
        }
               
        return ans;
    }
};
