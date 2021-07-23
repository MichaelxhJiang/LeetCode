class Solution {
public:
    /* 
    problem starts at k, n
    if drop ball on floor i, 
        doesn't break -> k, n-i
        if break -> k-1, i-1
    
    dp[k][n] = min for 1<=i<=n: max(dp[k][n-i], dp[k-1][i-1])
    
    intuitively, low i means dp[k][n-i] requires a lot of tries, 
    dp[k-1][i-1] requires very little tries
    
    high i means opposite
    
    so we can binary search i based on the values of dp[k][n-i] and dp[k-1][i-1]
    
    k*n subproblems
    each subproblem requires logn binary search
    
    O(knlogn)
    */
    vector<vector<int>> memo;
    
    int superEggDrop(int k, int n) {
        memo = vector<vector<int>>(k+1, vector<int>(n+1, -1));
        return recur(k, n);
    }
    
    int recur(int k, int n) {
        if (n == 0) {
            return 0;
        }
        if (k == 1) {
            return n;
        }
        if (memo[k][n] == -1) {
            //binary search for optimal i
            int low = 1;
            int high = n;
            int minimum = n;
            while (low <= high) {
                int i = (low+high)/2;
                int res1 = recur(k, n-i);   //didn't break
                int res2 = recur(k-1, i-1); //broke
                minimum = min(minimum, max(res1, res2));
                if (res1<res2) high = i-1;
                else if (res1>res2) low = i+1;
                else break;
            }
            
            memo[k][n] = 1+minimum;
        }
        
        return memo[k][n];
    }
};
