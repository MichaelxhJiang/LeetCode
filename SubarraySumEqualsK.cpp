class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // find two prefix sums that differ by k (sort of like 2SUM)
        
        int count = 0;
        unordered_map<int, int> map;    // prefix sum -> frequency
        map.insert({0, 1});
        
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (map.find(sum-k) != map.end()) count += map[sum-k];
            
            if (map.find(sum) == map.end()) map.insert({sum, 1});
            else map[sum]++;
        }
        
        return count;
    }
};
