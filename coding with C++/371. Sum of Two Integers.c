/*
 @ July 8 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 371. Sum of Two Integers
* 
   Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

   Example:
     Given a = 1 and b = 2, return 3.

*/
	 



/**
use bit operation.
*/


class Solution {
public:
    int getSum(int a, int b) {
       while(b){
           int flag = a & b;
           a = a ^ b;
           b = flag<<1;
       }
       return a;
     
    }
};