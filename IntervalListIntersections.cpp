class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int p1 = 0;
        int p2 = 0;
        while (p1 < firstList.size() && p2 < secondList.size()) {
            if (firstList[p1][1] >= secondList[p2][0] && firstList[p1][0] <= secondList[p2][1]) {
                ans.push_back(vector<int>{max(firstList[p1][0], secondList[p2][0]), min(firstList[p1][1], secondList[p2][1])});
            }
            
            if (firstList[p1][1] <= secondList[p2][1]) p1++;
            else p2++;
        }
        
        return ans;
    }
};
