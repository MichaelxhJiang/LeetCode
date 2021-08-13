class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> prefixSum = vector<int>(length, 0);
        for (int i = 0; i < updates.size(); i++) {
            prefixSum[updates[i][0]] += updates[i][2];
            if (updates[i][1]+1 < length) {
                prefixSum[updates[i][1]+1] -= updates[i][2];
            }
        }
        for (int i = 1; i < length; i++) {
            prefixSum[i] += prefixSum[i-1];
        }
        return prefixSum;
    }
};
