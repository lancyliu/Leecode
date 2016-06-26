/*
 @ Jun 24 2016 Monday
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 190. Reverse Bits
* 
   Reverse bits of a given 32 bits unsigned integer.

   For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), 
   return 964176192 (represented in binary as 00111001011110000010100101000000).

   Follow up:
     If this function is called many times, how would you optimize it?

     Related problem: Reverse Integer

*/
	 


/*

*/
class Solution {
public:
   vector<int> bitnum; // at first bitnum is 32bits of 0
     void calBinary(uint32_t n)
   {
	   if(n == 0) return;
       uint32_t next = n /2;
	   if(next == 0)
	   {
		   bitnum.push_back(n);
		   return;
	   }
       uint32_t resi = n%2;
        bitnum.push_back(resi);
        calBinary(next);
        return;
   }
    uint32_t reverseBits(uint32_t n) {
        //step1: caculate the binary number of n
        calBinary(n);
        
        //step2: reverse it.
        //step3: caculate the new number in 10 representation.
          //start from index = 0, 
		if(bitnum.empty()) return 0; // empty means n = 0.
         // int size = bitnum.size();
          int result = 0;
          for(unsigned i = 0; i < bitnum.size(); i++)
          {
              result += bitnum.at(i) * pow((double)2, (int)(32 -1 -i));
          }
         return result;
        
    }
};