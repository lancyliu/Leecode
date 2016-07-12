/*
 @ July 10 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 3. Longest Substring Without Repeating Characters
* 
    Given a string, find the length of the longest substring without repeating characters.

    Examples:

    Given "abcabcbb", the answer is "abc", which the length is 3.

    Given "bbbbb", the answer is "b", with the length of 1.

    Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/
	 



/**
use a string type vector to store the result, however, the last element in vector is the result(longest Substring Without Repeating Characters).
only if the substring is longer than the last element, it will be stored in the result vector and became the new 'last element'.
in order to speed up the algorithm: in the parttern of : abc abc abc, I use an if-else function to skip the repeating part. since the max-substr-length is the length of repeating elements.


*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        if(s.size()==1) return 1;
        vector<string> result;
        int i=0;
        while(i<s.size()){
            
            if(!result.empty()){
				//if result is not empty, we should check if there is an repeating substr.
                string s1 = result.at(result.size()-1);
                int size = s1.size();
                if(s.substr(i,size) == s1) {
					//if there are an repeating substr, index(i) should skip the repeating part to the new element.
                    i=i+size;
					//check the following elements in input string s, if it can be added to the result or if not.
                    for(unsigned j=i; j<s.size(); j++){
                    unsigned m=0;
                    for(m; m<s1.size();m++){
                        if(s1.at(m) == s.at(j)) break;
                       }
                    if(m==s1.size()) s1.push_back(s.at(j));
                    else break;
                 }
                 
                 result.push_back(s1);
                }
                else {
					
					//if there are no repeating substr. just scan the element.
					//use string substr to store currently substring Without Repeating Characters
					// for each element in input string s, we compare it to the elements in substr.
					// after caculated the current substr, if its length is longer than current result, push is into the result vector.
                    int len;
                    if(result.empty()) len=0;
                    else len = result.at(result.size()-1).size();
            
                    string substr;
                    substr.push_back(s.at(i));
                    for(unsigned j=i+1; j<s.size(); j++){
                        unsigned m=0;
                        for(m; m<substr.size();m++){
                        if(substr.at(m) == s.at(j)) break;
                       }
                     if(m==substr.size()) substr.push_back(s.at(j));
                      else break;
                      }
                     if(substr.size() > len) result.push_back(substr);
                     i++;
                  }
                }
            else{
                //result is empty
               
                string substr;
                substr.push_back(s.at(i));
                for(unsigned j=i+1; j<s.size(); j++){
                unsigned m=0;
                for(m; m<substr.size();m++){
                    if(substr.at(m) == s.at(j)) break;
                }
                if(m==substr.size()) substr.push_back(s.at(j));
                else break;
               }
               result.push_back(substr);
               i++;
            }
        }
        return result.at(result.size()-1).size();
    }
};