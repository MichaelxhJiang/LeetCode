class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> numOdd; // map # odd -> occurences
        int count = 0;
        int ans = 0;
        numOdd.insert({0, 1});
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 1) count++;
            if (numOdd.find(count-k) != numOdd.end()) {
                ans += numOdd[count-k];
            }
            if (numOdd.find(count) == numOdd.end()) {
                numOdd.insert({count, 1});
            } else {
                numOdd[count]++;
            }
        }
        
        return ans;
    }
};
