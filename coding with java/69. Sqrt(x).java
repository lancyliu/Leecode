/*
 @ July 27 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  69. Sqrt(x)
* 
    Implement int sqrt(int x).

    Compute and return the square root of x.


*/
	 

/**
if i*i < x and (i+1)*(i+1) >x then i is the result.
*/
public class Solution {
    public int mySqrt(int x) {
        if(x <0) return x;
        int i=0;
        int result;
        if(i*i >=x) result =i;
        else{
            ++i;
            while(i*i <=x){
                ++i;
                if(i > 46340) break;
            }
            result = i-1;
       }
       return result;
    }
}