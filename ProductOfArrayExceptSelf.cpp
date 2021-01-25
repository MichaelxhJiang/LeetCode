class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // for O(1) space, compute the left product in output vector
        // and compute the right product on the fly (eg. int rp) by iterating n -> 0
        
        vector<int> leftProduct(nums.size(), 0);
        vector<int> rightProduct(nums.size(), 0);
        leftProduct[0] = 1;
        rightProduct[nums.size()-1] = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            leftProduct[i] = leftProduct[i-1]*nums[i-1];
        }
        for (int i = nums.size()-2; i >= 0; i--) {
            rightProduct[i] = rightProduct[i+1]*nums[i+1];
        }
        
        vector<int> output;
        for (int i = 0; i < nums.size(); i++) {
            output.push_back(leftProduct[i] * rightProduct[i]);
        }
        
        return output;
    }
};
