class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        vector<int> largest = vector<int>(3, INT_MIN);
        vector<int> smallest = vector<int>(2, INT_MAX);
        
        for (int n : nums) {
            if (n > largest[0]) {
                largest[2] = largest[1];
                largest[1] = largest[0];
                largest[0] = n;
            } else if (n > largest[1]) {
                largest[2] = largest[1];
                largest[1] = n;
            } else if (n > largest[2]) {
                largest[2] = n;
            } 
            if (n < smallest[0]) {
                smallest[1] = smallest[0];
                smallest[0] = n;
            } else if (n < smallest[1]) {
                smallest[1] = n;
            }
        }
        
        return max(largest[2]*largest[1]*largest[0],
            smallest[0]*smallest[1]*largest[0]);
    }
};
