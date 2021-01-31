class SparseVector {
public:
    vector<pair<int, int>> sparse;
    
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                sparse.push_back({i, nums[i]});
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int p1 = 0;
        int p2 = 0;
        int sum = 0;
        while (p1 < sparse.size() && p2 < vec.sparse.size()) {
            if (sparse[p1].first == vec.sparse[p2].first) {
                sum += sparse[p1].second * vec.sparse[p2].second;
                p1++;
            } else if (sparse[p1].first > vec.sparse[p2].first) {
                p2++;
            } else {
                p1++;
            }
        }
        
        return sum;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
