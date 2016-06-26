/*
 @ Jun 25 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 172. Factorial Trailing Zeroes
* 
   Given an integer n, return the number of trailing zeroes in n!.

   Note: Your solution should be in logarithmic time complexity..

*/
	 


/*
The idea is learned from one blog in the internet.(http://bookshadow.com/weblog/2014/12/30/leetcode-factorial-trailing-zeroes/)
However, we should change the type of int --> long int in c++.
*/
class Solution {
public:
  

    int trailingZeroes(int n) {
        
       if(n <= 0) return 0;
       long int x = 5;
       long int result = 0;
       while(n >= x){
           long int temp = n / x;
           result += temp;
            x = x *5;
       }
       return result;
        
       
    }
};