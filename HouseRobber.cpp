class Solution {
public:
    int rob(vector<int>& nums) {
        int ans;
        vector<int> dp;
        for (int num : nums) dp.push_back(num);
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i-2; j >= 0; j--) {
                dp[i] = max(dp[i], nums[i]+dp[j]);
            }
            if (dp[i] > ans) ans = dp[i];
        }
        
        return ans;
    }
};
