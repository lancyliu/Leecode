/*
 @ July 6 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 13. Roman to Integer
* 
   Given a roman numeral, convert it to an integer.

   Input is guaranteed to be within the range from 1 to 3999.

*/
	 



/**

*/
	 
class Solution {
public:
    int romanToInt(string s) {
        if(s.empty()) return 0;
        map<char,int> roman;
        roman.insert(pair<char,int>(' ',0));
        roman.insert(pair<char,int>('I',1));
        roman.insert(pair<char,int>('V',5));
        roman.insert(pair<char,int>('X',10));
        roman.insert(pair<char,int>('L',50));
        roman.insert(pair<char,int>('C',100));
        roman.insert(pair<char,int>('D',500));
        roman.insert(pair<char,int>('M',1000));
        
        int result =0;
        for(unsigned i =0; i<s.size(); i++){
            int temp = roman.at(s.at(i));
            if(i < s.size()-1){
                if(temp >= roman.at(s.at(i+1))) result += temp;
                else result -= temp;
            }
            else result = result + temp;
            
        }
        return result;
        
    }
};