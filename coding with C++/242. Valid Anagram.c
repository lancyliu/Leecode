/*
 @ July 8 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 242. Valid Anagram
* 
    Given two strings s and t, write a function to determine if t is an anagram of s.

    For example,
      s = "anagram", t = "nagaram", return true.
      s = "rat", t = "car", return false.

    Note:
      You may assume the string contains only lowercase alphabets.

    Follow up:
      What if the inputs contain unicode characters? How would you adapt your solution to such case?

*/
	 



/**
for each element in string t, check if this element exits in string s, if yes, delete the element in string s, and continue to scan next in string t.
after we scan all the elements in string t, if string s is not empty, the result is also false.
*/


class Solution {
public:
    bool isAnagram(string s, string t) {
        int i=0;
        bool flag;
        while(i<t.size()){
            flag = false;
            for(unsigned j=0; j<s.size(); j++){
                if(s.at(j) == t.at(i)){
                    s.erase(s.begin()+j);
                    flag = true;
                    break;
                }
            }
            if(!flag) return false;
            else ++i;
        }
        if(s.empty())
        return true;
        else return false;
    }
};