class Solution {
public:
    map<int, int> weights;  // cumulative weight -> index
    int totalWeight;
    Solution(vector<int>& w) {
        int prefixWeights = 0;
        for (int i = 0; i < w.size(); i++) {
            prefixWeights += w[i];
            weights.insert({prefixWeights, i});
        }
        totalWeight = prefixWeights;
    }
    
    int pickIndex() {
        int random = rand() % totalWeight + 1;
        auto it = weights.lower_bound(random);
        return it->second;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
