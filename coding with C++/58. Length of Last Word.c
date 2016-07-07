/*
 @ July 2 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 58. Length of Last Word
* 
   Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

   If the last word does not exist, return 0.

   Note: A word is defined as a character sequence consists of non-space characters only.

   For example, 
    Given s = "Hello World",
    return 5.

*/
	 



/**
*/
	 
class Solution {
public:
    int lengthOfLastWord(string s) {
        //if string is empty, then result is 0;
		if(s.empty()) return 0;  
		
		//if string is not empty, we use ' ' to divide string s into several string which stored in a vector.
        vector<string> words;
        string temp;
        for(unsigned i=0; i<s.size(); i++){
            
            if(s.at(i)!= ' '){
                temp.push_back(s.at(i));
            }
            else if(s.at(i)==' ' && !temp.empty()){
                    words.push_back(temp);
                    temp.clear();
            }
        }
		//this is the last words in the string s.
       if(!temp.empty()) words.push_back(temp);
	   //if vector is not empty, return the length of the word. else return 0.
       if(!words.empty()){
           temp = words.at(words.size()-1);
           return temp.size(); 
        }
        else return 0;
        
    }
};