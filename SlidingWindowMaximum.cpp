class Solution {
public:
    // brute force (n-k)*k
    
    // deque, store indices in current window, sorted left to right
    // as you slide the window, delete first element, add new element to the back
    // but also, remove all elements to the left of the new element that are smaller
    // to maintain the sorted order
    // that way, we can always retrieve the max in the interval in O(1) since it's the 
    // first element in the deque
    // at most, we will process each element once (O(n))
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> output;
        //fill up the initial window
        for (int i = 0; i < k; i++) {
            clean(dq, nums, i, k); // slide window forward, remove smaller elements to maintain order
        }
        output.push_back(nums[dq.front()]);
        
        //slide the window
        for (int i = k; i < nums.size(); i++) {
            clean(dq, nums, i, k);
            output.push_back(nums[dq.front()]);
        }
        
        return output;
    }
    
    void clean(deque<int>& dq, vector<int>& nums, int i, int k) {
        // pop front if out of window
        // i increments by one each time so at most only one element
        // can be out of the window (no need for while loop)
        if (!dq.empty() && dq.front() <= i-k) {
            dq.pop_front();
        }
        
        // remove elements smaller than nums[i]
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }
        
        // insert i
        dq.push_back(i);
    }
};
