class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int, int> map; // prefix sum, index
        map.insert({0, -1});
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            // always mod k to keep sum within 0 to k
            if (k != 0) {
                sum %= k;
            }
            
            // if the same modulus occured before, then the interval
            // between the previous occurence and this index has a sum
            // that is a multiple of k
            if (map.count(sum)) {
                if (map[sum] < i-1) return true;
            } else {
                map.insert({sum, i});
            }
            
        }
        
        return false;
    }
};
