class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int ans = 0;
        int bound = sqrt(2*N);
        
        for (int k = 1; k <= bound; k++) {
            if ((N - (k*(k-1))/2) % k == 0) {
                ans++;
            }
        }
        
        return ans;
    }
};
