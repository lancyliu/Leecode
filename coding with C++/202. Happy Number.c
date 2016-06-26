/*
 @ Jun 22 2016 Monday
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 202. Happy Number
* 
   Write an algorithm to determine if a number is "happy".

   A happy number is a number defined by the following process: 
     Starting with any positive integer, replace the number by the sum of the squares of its digits, 
	 and repeat the process until the number equals 1 (where it will stay), 
	 or it loops endlessly in a cycle which does not include 1. 
	 Those numbers for which this process ends in 1 are happy numbers.


   Example: 19 is a happy number

      12 + 92 = 82
      82 + 22 = 68
      62 + 82 = 100
      12 + 02 + 02 = 1

*/
	 


/*
1. add a new function CalSqu to caculate: the sum of the squares of a number's digits
2. use vector to store the number that has been already caculated, if we meet this number again, the result is false.
3. once the number become 1, the function return true.
*/
class Solution {
public:
   int CalSqu(int n)
   {
        //change n to string to check the length.
        int x = n;
		string strn = to_string(x);
        int result = 0;
        for(unsigned i = 0; i<strn.size(); i++)
        {
            char temp = strn.at(i);    
            int t = (int)temp - 48;//atoi(temp2); //do not use atoi function to avoid complexity.
            result += t*t;
        }
        return result;
    }
	
   bool isHappy(int n) 
   {
        if(n == 1) return true;
        vector<int> result;
        while( n != 1)
        {
            int m = CalSqu(n);
            if(m == 1) return true;
            for(unsigned i = 0; i < result.size(); i++)
            {
                if( m == result.at(i)) return false;
            }
            result.push_back(m);
            n = m;
        }
        return false;  // if delete this sentence, there will be an error message.
    }
    
};