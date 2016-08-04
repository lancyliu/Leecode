/*
 @ Aug 4 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  91. Decode Ways
* 
    A message containing letters from A-Z is being encoded to numbers using the following mapping:

   'A' -> 1
   'B' -> 2
    ...
   'Z' -> 26
   Given an encoded message containing digits, determine the total number of ways to decode it.

   For example,
    Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

    The number of ways decoding "12" is 2. []



*/
	 

/**

*/
public class Solution {
    public int numDecodings(String s) {
        int[] result = new int[s.length() + 1];
        if(s.length() == 0 || (s.length() == 1 && s.charAt(0) == '0')) return 0;
        else if(s.length() == 1 && s.charAt(0) != '0') return 1;
        
        result[0]=1;
        result[1] = 1;
        for(int i=0; i<s.length(); ++i){
            char c = s.charAt(i);
            int t = (int)c - 48;
            if(i==0 && t ==0) return 0;
            if(t==0) result[i] = 0;
            if(i!=0){
                char cp = s.charAt(i-1);
                int tp = (int)cp - 48;
                if((tp == 1) || (tp == 2 && t <= 6) ) result[i+1] = result[i-1] + result[i];
                else {
                    result[i+1] = result[i];
                }
            }
        }
        return result[s.length()];
    }
    
}