/*
 @ July 7 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 8. String to Integer (atoi)
* 
   Implement atoi to convert a string to an integer.

   Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

   Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

*/
	 



/**
the most import part is to consider all the possible input string. like string include blank spaces, + -, or string is bigger than the limitation in C++.
*/

class Solution {
public:
    int myAtoi(string str) {
        if(str.empty()) return 0;
        int result =0;
        bool flag = true;
        //remove zeros in the beginning of the string
        int m=0;
        while(m <str.size()){
            char c = str.at(m);
            if(c==' ') str.erase(str.begin());
            else break;
        }
        //if there is one '-' then this number should be smaller than 0
        //check the string and remove'-'or '+' in the beginning of string
        if(str.at(0) == '-') {
            flag = false;
            str.erase(str.begin());
        }
        else if(str.at(0) == '+') str.erase(str.begin());
        
        if(str.empty()) return 0;
        //if there are still some element in string that is not a number, we should remove the symbol and elements behind it.
        int j=0;
        while(j<str.size()){
            char c = str.at(j);
            int t = (int)c - 48;
            if(t<0 || t>9) {
                str.erase(str.begin()+j,str.end());
                break;
            }
            else j++;
        }
        //for now the string only contian the numbers
        int i=0;
        while (i<str.size()){
            char c = str.at(i);
            int t = (int)c - 48;
            //if(t<0 || t>9) break;
            //else {
            if((result+t*pow(10,str.size()-1-i)>=2147483647) && flag){
                result = 2147483647;
                break;
                }
            else if(!flag &&(result+t*pow(10,str.size()-1-i)>=2147483648)){
                result = 2147483648;
                break;
            }
               else result += t*pow(10,str.size()-1-i);
               ++i;
            //}
        }
        if(flag==false) result = result*(-1);
        return result;
    }
};