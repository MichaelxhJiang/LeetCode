class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // memoize the number of ways to sum to i
        vector<unsigned long long> memo(target+1);
        int size = nums.size();
        memo[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < size; j++) {
                if (i >= nums[j]) {
                    memo[i] += memo[i-nums[j]];
                }
            }
        }
        
        return memo[target];
    }
};
