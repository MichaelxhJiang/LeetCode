class UnionFind {
    private:
        vector<int> parent;
        vector<int> rank;
    public:
        UnionFind(int N) {
            rank.assign(N, 0);
            parent.assign(N, 0);
            for (int i = 0; i < N; i++) parent[i] = i;
        }
    
        int findSet(int i) {
            return (parent[i] == i) ? i : (parent[i] = findSet(parent[i]));
        }
    
        bool isSameSet(int i, int j) {
            return findSet(i) == findSet(j);
        }
    
        void unionSet(int i, int j) {
            if (!isSameSet(i, j)) {
                int x = findSet(i);
                int y = findSet(j);
                if (rank[x] > rank[y]) {
                    parent[y] = x;
                } else {
                    parent[x] = y;
                    if (rank[x] == rank[y]) rank[y]++;
                }
            }
        }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        UnionFind uf(10001);
        unordered_map<string, int> emailIndex;
        unordered_map<string, string> emailName;
        
        cout << "1" << endl;
        
        int index = 0;
        for (vector<string>& acc : accounts) {
            string name = acc[0];
            for (int i = 1; i < acc.size(); i++) {
                string email = acc[i];
                if (emailIndex.find(email) == emailIndex.end()) {
                    emailIndex.insert({email, index++});
                }
                if (emailName.find(email) == emailName.end()) {
                    emailName.insert({email, name});
                }
                // union with previous
                if (i > 1) {
                    uf.unionSet(emailIndex[email], emailIndex[acc[i-1]]);
                }
            }
        }
        
        unordered_map<int, vector<string>> emailChain;
        for (auto& emidx : emailIndex) {
            int parent = uf.findSet(emidx.second);
            if (emailChain.find(parent) == emailChain.end()) {
                emailChain.insert({parent, vector<string>()});
            }
            emailChain[parent].push_back(emidx.first);
        }
        
        vector<vector<string>> ans;
        for (auto& emails : emailChain) {
            string name = emailName[emails.second[0]];
            sort(emails.second.begin(), emails.second.end());
            
            vector<string> row;
            row.push_back(name);
            for (string email : emails.second) {
                row.push_back(email);
            }
            
            ans.push_back(row);
        }
        
        
        
        return ans;
    }
};
