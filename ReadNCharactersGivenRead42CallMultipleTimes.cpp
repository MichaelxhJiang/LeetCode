/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    char buf4[4];   //used for read4
    int index = 0;    // used to track current buf4 position
    int left = 0;   // unused characters in buf4
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int count = 0;
        
        if (!left) {
            left = read4(buf4);
            index = 0;
        }
        
        while (count < n && left) {
            buf[count++] = buf4[index++];
            left--;
            if (left == 0) {
                left = read4(buf4);
                index = 0;
            }
        }
        
        return count;
    }
};
