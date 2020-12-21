class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // insert new interval into intervals
        bool insert = false;
        for (int i = 0; i < intervals.size(); i++) {
            if (!insert && intervals[i][0] >= newInterval[0]) {
                intervals.insert(intervals.begin()+i, newInterval);
                insert = true;
                break;
            }
        }
        if (!insert) intervals.push_back(newInterval);
        
        vector<vector<int>> ans;
        vector<bool> merged(intervals.size());
        for (int i = 0; i < intervals.size(); i++) {
            if (merged[i]) continue;
            
            // try to merge with other intervals
            for (int j = i+1; j < intervals.size(); j++) {
                if (intervals[i][1] >= intervals[j][0]) {
                    intervals[i][1] = max(intervals[i][1], intervals[j][1]);
                    merged[j] = true;
                }
            }
            ans.push_back(intervals[i]);
        }
        
        return ans;
    }
};
