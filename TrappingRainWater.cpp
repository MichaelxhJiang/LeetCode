class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        
        vector<int> maxLeft(height.size(), 0);
        vector<int> maxRight(height.size(), 0);
        maxLeft[0] = height[0];
        maxRight[height.size()-1] = height[height.size()-1];
        for (int i = 1; i < height.size(); i++) {
            maxLeft[i] = max(maxLeft[i-1], height[i-1]);
        }
        for (int i = height.size()-2; i >= 0; i--) {
            maxRight[i] = max(maxRight[i+1], height[i+1]);
        }

        int total = 0;
        for (int i = 0; i < height.size(); i++) {
            int rain = min(maxLeft[i], maxRight[i]) - height[i];
            if (rain > 0) total += rain;
        }

        return total;
    }
};
