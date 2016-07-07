/*
 @ July 1 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 70. Climbing Stairs
* 
   You are climbing a stair case. It takes n steps to reach to the top.

   Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

*/
	 



/**
climbStairs(n) = climbStairs(n-1) +climbStairs(n-2);
use fibonacci number to caculate the result.
*/
	 
class Solution {
public:
    vector<int> number;
    int climbStairs(int n) {
        if(n <= 0) return 0;
        else if(n == 1) return 1;
        else if(n == 2) return 2;
        else{
            
           
          n = n+1;
           double q = (1+sqrt(5)) /2;
           double p = (1-sqrt(5)) /2;
           double result = pow(q,n) - pow(p,n);
           result = result/(sqrt(5));
           int r = (int)result;
           return r;
        }
        
        
    }
};