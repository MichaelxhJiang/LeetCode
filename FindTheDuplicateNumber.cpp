class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Hash Set Method
        unordered_set<int> found;
        for (int num : nums) {
            if (found.find(num) != found.end()) return num;
            found.insert(num);
        }
        
        return -1;
    }
    
};
