class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickselect(nums, 0, nums.size()-1, nums.size()-k);
    }
    
    int quickselect(vector<int>& nums, int l, int r, int k) {
        /*
        Returns the k-th smallest element of list within left..right.
        */
        if (l == r) // If the list contains only one element,
            return nums[l];  // return that element

        // select a random pivot_index
        int pivot = rand() % (r-l+1) + l; 
        swap(nums[l], nums[pivot]);

        int mid = partition(nums, l, r);

        // the pivot is on (N - k)th smallest position
        if (k == mid)
          return nums[k];
        // go left side
        else if (k < mid)
          return quickselect(nums, l, mid - 1, k);
        // go right side
        return quickselect(nums, mid + 1, r, k);
    }
    
    int partition(vector<int>& nums, int i, int j) {
        int ti = i;
        int pivot = nums[i];
        i++;
        
        while (true) {
            while (i < j && nums[i] <= pivot) i++;
            while (j >= i && nums[j] >= pivot) j--;
            
            if (i >= j) break;
            swap(nums[i], nums[j]);
        }
        
        swap(nums[ti], nums[j]);
        return j;
    }
};
