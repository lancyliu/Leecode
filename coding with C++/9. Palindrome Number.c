/*
 @ July 7 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 9. Palindrome Number
* 
   Determine whether an integer is a palindrome. Do this without extra space.

*/
	 



/**
while x smaller than 0, the result is false.
*/

class Solution {
public:
    bool isPalindrome(int x) {
      if(x <0) return false;
      cout<<x;
      if( x<10) return true;
      string s = to_string(x);
      //cout<<s;
      for(unsigned i=0; i<s.size() /2; ++i){
          if(s.at(i) != s.at(s.size()-1-i)) return false;
      }
      return true;
    }
};