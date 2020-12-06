class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), 
             [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        int ans = 0;
        int i1 = 0;
        int i2 = 1;
        while (i2 < intervals.size()) {
            if (intervals[i1][1] <= intervals[i2][0]) {
                i1 = i2;
                i2++;
            } else if (intervals[i1][1] >= intervals[i2][1]) {
                i1 = i2;
                i2++;
                ans++;
            } else {
                i2++;
                ans++;
            }
        }
        
        return ans;
    }
};
