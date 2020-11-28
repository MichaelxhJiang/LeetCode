class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        vector<int> dp(nums.size(), 1);
        int ans = 1;
        for (int i = 0; i < nums.size(); i++) {
            
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            
            if (dp[i] > ans) ans = dp[i];
        }
        
        return ans;
    }
};
