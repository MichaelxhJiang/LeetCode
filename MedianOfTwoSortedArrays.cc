class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a = nums1;
        vector<int> b = nums2;
        
        if (nums1.size() > nums2.size()) {
            a = nums2;
            b = nums1;
        }
        
        int min = 0;
        int max = a.size();
        int i, j;
        
        while (min <= max) {
            i = (min+max)/2;
            j = (a.size() + b.size()+1)/2 - i;
            
            if (i > 0 && a.at(i-1) > b.at(j)) {
                //decrease i, increase j
                max = i-1;
            } else if (i < a.size() && b.at(j-1) > a.at(i)) {
                //decrease j, increase i
                min = i+1;
            } else {
                double maxLeft = 0;
                double minRight = 0;
                if (i == 0) {
                    maxLeft = b.at(j-1);
                } else if (j == 0) {
                    maxLeft = a.at(i-1);
                } else {
                    maxLeft = std::max(a.at(i-1), b.at(j-1));
                }
                
                if ((a.size()+b.size()) % 2 == 1) {
                    return maxLeft;
                }
                
                if (i == a.size()) {
                    minRight = b.at(j);
                } else if (j == b.size()) {
                    minRight = a.at(i);
                } else {
                    minRight = std::min(b.at(j), a.at(i));
                }
                 
                return (minRight + maxLeft)/2.0;
            }
        }
        return 0.0;
    }
};
