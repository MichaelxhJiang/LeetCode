class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i1 = m - 1;
        int i2 = n - 1;
        int index = nums1.size() - 1;
        
        while (i1 >= 0 & i2 >= 0) {
            if (nums1[i1] > nums2[i2]) {
                nums1[index--] = nums1[i1--];
            } else {
                nums1[index--] = nums2[i2--];
            }
        }
        while (i1 >= 0) {
            nums1[index--] = nums1[i1--];
        }
        while (i2 >= 0) {
            nums1[index--] = nums2[i2--];
        }
    }
};
