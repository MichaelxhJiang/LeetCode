class Solution {
public:
// O(n^3) solution
//     int ans;
    
//     int threeSumSmaller(vector<int>& nums, int target) {
//         sort(nums.begin(), nums.end());
//         for (int i = 0; i < nums.size(); i++) {
//             twoSumSmaller(i, nums, target-nums[i]);
//         }
        
//         return ans;
//     }
    
//     void twoSumSmaller(int i, vector<int>& nums, int target) {
//         for (int j = i+1; j < nums.size(); j++) {
//             // subsequent elements can only be larger/equal to j
//             if (nums[j] >= target) return;
//             int kTarget = target-nums[j];
//             for (int k = j+1; k < nums.size() && nums[k] < kTarget; k++) {
//                 ans++;
//             }
//         }        
//     }
    
    int ans;
    
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans += twoSumSmaller(i, nums, target-nums[i]);
        }
        
        return ans;
    }
    
    int twoSumSmaller(int i, vector<int>& nums, int target) {
        int ans = 0;
        // two pointer, # pairs < target = right pointer - left pointer
        int left = i+1;
        int right = nums.size()-1;
        while (left < right) {
            if (nums[left] + nums[right] < target) {
                ans += right-left;
                left++;
            } else {
                right--;
            }
        }
        
        return ans;
    }
};
