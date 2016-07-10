/*
 @ July 9 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 20. Valid Parentheses
* 
    Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

    The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

*/
	 



/**
Once we found one pair(this one pair means the characters in index i  & i+1, and are correct characters), we delete this pair, and check the remaining string
loop to find,delete the pairs.
*/

class Solution {
public:
    bool isValid(string s) {
        string correct ("(){}[]");
        int size = s.size();
        if(s.empty()) return true;
        else if(size %2 != 0) return false;
        else{
            int i=0;
            while(i<s.size()-1){
                char c = s.at(i);
                int j=0;
                char next;
                //find what the next element should be(stores in char next)
                for(unsigned j=0; j<correct.size(); j++){
                   if(c == correct.at(j)){
                       if(j%2 != 0) return false;
                       else next = correct.at(j+1);
                   }
                }
                //check index i+1 if it equal next, then delete element in i, i+1, and check string s is valid or not
				//if index i+1 is not equal next, then i=i+1
                if(s.at(i+1) == next){
                   s.erase(s.begin()+i);
                   s.erase(s.begin()+i);
                   return isValid(s);
                }
                else i+= 1;
            }
            return false;
        }
    }
    
};