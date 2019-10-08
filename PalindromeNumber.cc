class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x % 10 == 0 && x != 0) return false;
        
        //1234321 reverted = 1234 x = 123
        int revertedNumber = 0;
        while (x > revertedNumber) {
            revertedNumber = revertedNumber*10 + x %10;
            
            x /= 10;
        }
        
        return revertedNumber == x || revertedNumber / 10 == x;
    }
};
