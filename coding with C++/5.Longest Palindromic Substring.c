/*
 @ July 11 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  5	Longest Palindromic Substring
* 
    Given a string S, find the longest palindromic substring in S. 
	You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

*/
	 



class Solution {
public:
    string longestPalindrome(string s) {
		
		//if s is empty or only contain one element just retrun s.
        if(s.empty() || s.size()==1) return s;
        
		//string result will store the result substr
		//substr will store the palindrome sub-string in each loop and then compared with current result. then updated the result if needed.
        string result;
        string substr ;
        int i=0;
        while(i<s.size()){
			//if the remaining substring is shorter than the result , break the loop.
            if(i+result.size() >= s.size()) break;
            else{ 
			    //scan the string from the tail, once we found one palindrome, break the inner loop.
                string temp;
                int j=s.size();
                while(j>i){
					//if sub-string size is smaller than result, break the inner loop.
					//if the head and tail of the substring is equal, call isPalindrome function to check
                   if(j-i <= result.size()) break;
                   else if(s.at(j-1) == s.at(i)){
                       substr = s.substr(i,j-i);
                       if(isPalindrome(substr)){
                          if(substr.size() >result.size()) result = substr;
                          break;
                          }
                       else if(result.size() >= (substr.size()-1)) break;
                       else j--;
                    }
                    else j--;
                }
                i++;
            }
        }
           
        return result;
    }
    
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        else{
            //there are two ways to check the string s is palindrome or not. however the former one is faster than latter.
			//method 1:
            int l=s.size();
            int t = l/2;
            for(int i=t-1; i>=0; i--){
                if(s.at(i) != s.at(l-1-i)) return false;
            }
            return true;
			//method 2:
            /**
            int l = s.size();
            for(int i =0; i < l/2 ; i++){
                char c1 = s.at(i);
                char c2 = s.at(l-1-i);
                if(c1 != c2) return false;
            }
            */
            
        }
    }

};