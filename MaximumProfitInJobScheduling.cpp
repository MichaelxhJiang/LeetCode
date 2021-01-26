class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int ans = 0;
        map<int, int> dp;   // end time -> max
        vector<vector<int>> jobs;
        for (int i = 0; i < startTime.size(); i++) {
            jobs.push_back(vector<int>{startTime[i], endTime[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end(), [](const vector<int> a, vector<int> b) {
            return a[0] > b[0]; // sort descending start times
        });
        
        for (auto job : jobs) {
            auto it = dp.lower_bound(job[1]);   // append this job to jobs (dp) that start after this one
            int prevMax = 0;
            if (it != dp.end()) {
                prevMax = it->second;
            }
            ans = max(ans, prevMax + job[2]);
            dp[job[0]] = ans;
        }
        
        return ans;
    }
};
