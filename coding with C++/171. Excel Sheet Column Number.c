/*
 @ Jun 26 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 171. Excel Sheet Column Number
* 
   Related to question Excel Sheet Column Title

   Given a column title as appear in an Excel sheet, return its corresponding column number.

   For example:

      A -> 1
      B -> 2
      C -> 3
      ...
      Z -> 26
      AA -> 27
      AB -> 28  

*/
	 


/*
According to problem 168, same process.

*/
class Solution {
public:
int titleToNumber(string s) {
        int result = 0;
        if(s.empty()) return 0;
        else{
            for(unsigned i = 0; i< s.size(); i++){
                char c = s.at(i);
                int temp = (int)c - 64;  // this to caculate the int type number match the char c. sice the number start from 1, we should -64.
                if(i != s.size() -1) result = result+ temp* pow(26,(s.size() -1 -i)); // this should use pow(26,*) not *26. 
				else result += temp;
            }
            return result;
        }
    }
};