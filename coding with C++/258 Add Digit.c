/*
 @ May 31 2016 Monday
 @ by Xin Liu 
*/

/**Description of the problem**/
/* LeetCode 258. Add Digits
* Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

* Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
* Could you do it without any loop/recursion in O(1) runtime?

Hint:

* A naive implementation of the above process is trivial. Could you come up with other methods?
* What are all the possible results?
* How do they occur, periodically or randomly?
* You may find this Wikipedia article useful.(https://en.wikipedia.org/wiki/Digital_root)
*/

// This problem use the digit root. 
// There is a formula to solve this problem. dr(n) = n - 9*[n/9];

class Solution {
public:
    int addDigits(int num) {
        if(num <= 0) return 0;
        if(num < 10) return num;
        int result;
        result = (num-1) / 9;
        result = result * 9;
        result = num - result;
        return result;
    }
};
