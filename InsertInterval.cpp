class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        
        //add all intervals before new interval
        int i = 0;
        while (i < intervals.size() && intervals[i][0] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }
        
        //insert new interval (either merge with previous or push back)
        if (ans.size() > 0 && ans[ans.size()-1][1] >= newInterval[0]) {
            ans[ans.size()-1][1] = max(ans[ans.size()-1][1], newInterval[1]);
        } else {
            ans.push_back(newInterval);
        }
        
        //for subsequent intervals, either merge or push back
        while (i < intervals.size()) {
            if (ans[ans.size()-1][1] >= intervals[i][0]) {
                ans[ans.size()-1][1] = max(ans[ans.size()-1][1], intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
            i++;
        }
        
        return ans;
    }
};
