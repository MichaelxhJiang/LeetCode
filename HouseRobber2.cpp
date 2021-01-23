class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        
        // consider either nums[0-N-1] or nums[1-N]
        return max(helper(nums, 0, nums.size()-1), helper(nums, 1, nums.size()));
    }
    
    int helper(vector<int>& nums, int start, int end) {
        int ans = 0;
        vector<int> dp;
        for (int num : nums) {
            dp.push_back(num);
        }
        
        for (int i = start; i < end; i++) {
            // check all non-adjacent houses
            for (int j = i-2; j >= start; j--) {
                dp[i] = max(dp[i], dp[j] + nums[i]);
            }
            
            if (dp[i] > ans) ans = dp[i];
        }
        
        return ans;
    }
};
