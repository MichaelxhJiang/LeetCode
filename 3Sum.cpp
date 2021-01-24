class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        
        vector<vector<int>> ans;
        
        for (int i = 0; i < nums.size() && nums[i] <= 0; ++i) {
            if (i == 0 || nums[i-1] != nums[i]) {
                unordered_set<int> set;
                for (int j = i+1; j < nums.size(); ++j) {
                    int complement = -nums[i] - nums[j];
                    if(set.count(complement)) {
                        ans.push_back({nums[i], nums[j], complement});

                        while (j+1 < nums.size() && nums[j] == nums[j+1]) ++j;    //skip duplicates only after retrieving the first answer since two duplicates may be a part of the answer
                    }
                    set.insert(nums[j]);
                }
            }
        }
        
        return ans;
    }
};
