/*
 @ May 30 2016 Monday
 @ by Xin Liu 
*/

/**Description of the problem**/
/* LeetCode 342. Power of Four
* Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

* Example:
* Given num = 16, return true. Given num = 5, return false.

* Follow up: Could you solve it without loops/recursion?

*/


/*
Using recursion to solve this problem. if this num is divisible by four, check if the division is power of 4.
*/
class Solution {
public:
    bool isPowerOfFour(int num) {
        //recursion
        if(num == 0) return false;
        if(num == 1) return true;
        int res = num % 4;
        int next = num /4;
        if(res == 0) return isPowerOfFour(next); 
        else return false;
    }
};