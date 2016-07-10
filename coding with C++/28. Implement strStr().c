/*
 @ July 9 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 28. Implement strStr()
* 
    Implement strStr().

    Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

    Subscribe to see which companies asked this question

*/
	 



/**

*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0;
		//if needle is empty the result will always be 0.
		// if haystack is empty or its size smaller than needle then result will be -1.
        if(needle.empty()) return 0;
        if(haystack.empty() && !needle.empty()) return -1;
        if(haystack.size() < needle.size()) return -1;
        while(i<haystack.size()){
			//in this loop, check the size of remainning haystack if its smaller than needle's size, return -1.
            if(haystack.size()-i < needle.size()) return -1;
            if(haystack.at(i) == needle.at(0)){
                int j=0;
                while(i+j <haystack.size() && j<needle.size()){
                    if(haystack.at(i+j) == needle.at(j)) j++;
                    else break;
                }
                if(j == needle.size()) return i;
            }
            i++;
        }
        return -1;
    }
};