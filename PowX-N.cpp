class Solution {
public:
    double myPow(double x, int n) {
        // Idea: x^n = (x^(n/2))^2
        if (n == 0) return 1;
        long long N = n;
        
        double ans = recur(x, abs(N));
        if (n < 0) return 1 / ans;
        return ans;
    }
    
    double recur(double x, long long n) {
        if (n == 1) return x;
        
        // make sure n is even
        double ans = 1;
        if (n % 2 == 1) {
            ans *= x;
            n--;
        }
        double half = recur(x, n/2);
        
        ans *= half*half;
        return ans;
    }
};
