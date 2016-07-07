/*
 @ July 1 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 66. Plus One
* 
   Given a non-negative number represented as an array of digits, plus one to the number.

   The digits are stored such that the most significant digit is at the head of the list.

*/
	 



/**
if the digit is 9, there should be a flip.
*/
	 
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        if(digits.at(size-1) <9) digits.at(size-1)++;
        else{
            int i=size;
            while(i>0){
                if(digits.at(i-1)==9) digits.at(i-1) =0;
                else {
                    digits.at(i-1) ++;
                    break;
                }
                i--;
            }
            if(digits.at(0)==0) digits.insert(digits.begin(),1);
        }
        return digits;
    }
};