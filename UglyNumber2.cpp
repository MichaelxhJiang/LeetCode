class Solution {
public:
    int nthUglyNumber(int n) {
        // 1 is first ugly
        // 3 pointers, each pointing to smallest element that hasn't been multiplied by
        // the prime
        vector<int> factors{2,3,5};
        vector<int> idx{0,0,0};
        vector<int> order(n);
        order[0] = 1;
        
        for (int i = 1; i < n; i++) {
            int next = -1;
            for (int j = 0; j < factors.size(); j++) {
                if (next == -1) next = factors[j]*order[idx[j]];
                else next = min(next, factors[j]*order[idx[j]]);
            }
            for (int j = 0; j < factors.size(); j++) {
                if (next == factors[j]*order[idx[j]]) idx[j]++;
            }
            
            order[i] = next;
        }
        
        return order[n-1];
    }
};
