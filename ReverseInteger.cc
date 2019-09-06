class Solution {
public:
    int reverse(int x) {
        bool neg = false;
        if (x == INT_MIN) return 0;
        
        if (x < 0) {
            neg = true;
            x = abs(x);
        }
        
        long reverse = 0;
        
        while (x > 0) {
            reverse *= 10;
            reverse += x%10;
            x /= 10;
            
            if (reverse > INT_MAX) return 0;
        }
        
        if (neg) reverse *= -1;
        
        return reverse;
    }
};
