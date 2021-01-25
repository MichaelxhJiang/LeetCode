class Solution {
public:
    map<int, string> ones;
    map<int, string> teens;
    map<int, string> tens;
    
    string numberToWords(int num) {
        ones[1] = "One";
        ones[2] = "Two";
        ones[3] = "Three";
        ones[4] = "Four";
        ones[5] = "Five";
        ones[6] = "Six";
        ones[7] = "Seven";
        ones[8] = "Eight";
        ones[9] = "Nine";
        
        teens[10] = "Ten";
        teens[11] = "Eleven";
        teens[12] = "Twelve";
        teens[13] = "Thirteen";
        teens[14] = "Fourteen";
        teens[15] = "Fifteen";
        teens[16] = "Sixteen";
        teens[17] = "Seventeen";
        teens[18] = "Eighteen";
        teens[19] = "Nineteen";
        
        tens[2] = "Twenty";
        tens[3] = "Thirty";
        tens[4] = "Forty";
        tens[5] = "Fifty";
        tens[6] = "Sixty";
        tens[7] = "Seventy";
        tens[8] = "Eighty";
        tens[9] = "Ninety";
        
        if (num == 0) {
            return "Zero";
        }
        
        string ans = "";
        
        // split num into groups of 3
        int billions = num / 1000000000;
        int millions = (num % 1000000000) / 1000000;
        int thousands = (num % 1000000) / 1000;
        int ones = num % 1000;
        
        if (billions) {
            ans += parseDigits(billions) + " Billion ";
        }
        
        if (millions) {
            ans += parseDigits(millions) + " Million ";
        }
        
        if (thousands) {
            ans += parseDigits(thousands) + " Thousand ";
        }
        
        if (ones) {
            ans += parseDigits(ones) + " ";
        }
        
        return ans.substr(0, ans.size()-1);
    }
    
    // helper function to break down 3 digits
    string parseDigits(int num) {
        if (num == 0) return "";
        
        string parsed;
        if (num < 10) {
            parsed = ones[num];
        } else if (num < 20) {
            parsed = teens[num];
        } else if (num < 100) {
            parsed = tens[num/10] + " " + parseDigits(num % 10);
        } else {
            parsed = ones[num/100] + " Hundred " + parseDigits(num % 100);
        }
        
        if (parsed[parsed.size()-1] == ' ') return parsed.substr(0, parsed.size()-1);
        return parsed;
    }
};
