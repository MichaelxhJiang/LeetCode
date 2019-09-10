class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        map<int, int> map; //map key with A[i] and value with i to get "smallest/largest possible value" for jumps with map::upper_bound
        bool odd[A.size()] = {false};
        bool even[A.size()] = {false};
        
        //mark last element as valid finishing point
        odd [A.size()-1] = true;
        even [A.size()-1] = true;
        
        int ans = 0;
        
        //iterate over the array backwards so that everything we store in the map
        //will always be to the right of the current index and "jumpable"
        for (int i = A.size()-1; i >= 0; i--) {
            //we can always jump to elements of the same value
            if (map.find(A[i]) != map.end()) {
                odd[i] = even[map[A[i]]];
                even[i] = odd[map[A[i]]];
            } else {
                //we need to find the "smallest/largest possible value" to jump to, if possible
                auto upper = map.upper_bound(A[i]); //this gets the smallest value > A[i]
                auto lower = map.end();
                if (upper != map.begin()) {
                    lower = prev(upper); //this gets the iterator to the largest value < A[i]
                }
                if (upper != map.end()) {
                    odd[i] = even[upper->second];
                }
                
                if (lower != map.end()) {
                    even[i] = odd[lower->second];
                }
            }
            
            if (map.find(A[i]) != map.end()) {
                map[A[i]] = i;
            } else {
                map.insert({A[i], i});
            }
            
            ans += odd[i] ? 1 : 0;
        }
        
        return ans;
    }
};
