/*
 @ July 21 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  50. Pow(x, n) 
* 
    Implement pow(x, n).

*/
	 

/**
Note : boundary conditions.
limitation of int, double. while x == 1 or -1.
*/

public class Solution {
    public double myPow(double x, int n) {
        //Map<Integer, double> myMap = new HashMap<Integer, double>();
        if(n==0) return (double)1;
        if(x == 1.000) return (double)1;
        if(x == -1.00000){
            if(n%2 ==0) return (double)1;
            else return (double)-1;
        }
        int i=1;
        double result = 1.00000;
      
        while(n >0 && i <= n){
            result = result * x;
           
            if(result >=0 && result < 0.000005){
                result = 0.00000;
                break;
            }
            if(result <0 && result > -0.000005){
                result = -0.00000;
                break;
            }
            
            i++;
        }
         i=-1;
        while(n <0 && i >= n){
           result = result *(1/x);
           if(result >=0 && result < 0.000005){
                result = 0.00000;
                break;
            }
            if(result <0 && result > -0.000005){
                result = -0.00000;
                break;
            }
            i--;
        }
      
        return result;
    }
}