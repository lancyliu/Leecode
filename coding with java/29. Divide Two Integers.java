/*
 @ July 18 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  29. Divide Two Integers
* 
    Divide two integers without using multiplication, division and mod operator.
 
    If it is overflow, return MAX_INT.

*/
	 

/**
Idea from:
http://bangbingsyb.blogspot.com/2014/11/divide-two-integers-divide-two-integers.html

*/

public class Solution {
   int MAX_INT = 2147483647;
   int MIN_INT = -2147483648;    
    public int divide(int dividend, int divisor) {
        if(divisor == 0){
            if(dividend >0) return MAX_INT;
            else return MIN_INT;
        }
        
        if(dividend == MIN_INT && divisor == -1) return MAX_INT;
        
        if(dividend > MAX_INT) dividend = MAX_INT;
        else if(dividend <MIN_INT) dividend = MIN_INT;
        
        if(divisor == 1) return dividend;
        else if(divisor == -1) return (0-dividend);
        
         long newdividend = Math.abs((long)dividend);
         long newdivisor = Math.abs((long)divisor);
         long copydivisor = newdivisor;
         long temp =0;
        int result =0;
        int i=0;
        while(temp <= newdividend) {
            temp = copydivisor<<i;
            i++;
        }
        
        while(newdividend >= newdivisor){
            if(newdividend >= copydivisor<<i){
                result += 1<<i;
                newdividend -= copydivisor<<i;
            }
            i--;
        }
        
        if((dividend>=0 && divisor>0) || (dividend <0 && divisor <0)) return result;
        else return (0-result);
        
        
        
    }
}