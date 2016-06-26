/*
 @ Jun 24 2016 Monday
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 191. Number of 1 Bits
* 
   Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

   For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.

*/
	 


/*
recursion
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        if(n == 0) return 0;
        uint32_t next;
        next = n /2;
        if(next == 0) return 1;
        else
        {
            uint32_t resi;
            resi = n % 2;
            //int result = 0;
            if(resi == 0) return hammingWeight(next);
            else return 1+hammingWeight(next);
        }
        
        
    }
};