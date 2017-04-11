/*
@ APR 11 2017
@ by Xin Liu
*/

/************Description of the problem************/
/* 125. Valid Palindrome
*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/


class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        else{
            unsigned i=0;
            // delete all the other characters in string.
            while(i < s.size()){
                char c = s.at(i);
                int t = (int)c;
                if(t<48 ||(t >57 && t<65) || (t>90 && t < 97) || t>122 ) s.erase(s.begin()+i);
                else 
                    i++;
     
            }
            //cout<<s;
            int l = s.size();
            for(int i =0; i < l/2 ; i++){
                //cout<<i<<endl;
                char c1 = s.at(i);
                char c2 = s.at(l-1-i);
                if(islower(c1)) c1 = toupper(c1);
                if(islower(c2)) c2 = toupper(c2);
                //cout<<c1<<endl; 
                //cout<<c2<<endl;
                if(c1 != c2) return false;
            }
            return true;
            
        }
    }
};