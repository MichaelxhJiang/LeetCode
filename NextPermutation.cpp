class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2) return;
        
        bool swapped = false;
        for (int i = nums.size()-1; i >= 1; i--) {
            if (nums[i] > nums[i-1]) {
                swapped = true;
                
                int t = i;
                while (t < nums.size() && nums[t] > nums[i-1]) t++;
                swap(nums[i-1], nums[t-1]);
                reverse(nums.begin()+i, nums.end());
                break;
            }
        }
        
        if (!swapped) {
            reverse(nums.begin(), nums.end());  
        }
    }
};
