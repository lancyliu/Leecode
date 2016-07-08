/*
 @ July 7 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 7. Reverse Integer
* 
   Reverse digits of an integer.

   Example1: x = 123, return 321
   Example2: x = -123, return -321

   click to show spoilers.

   Have you thought about this?
    Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

    If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

    Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

    For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

   Update (2014-11-10):
    Test cases had been added to test the overflow behavior.

*/
	 



/**
1.convert it to string
2. caculate the reverse number
*/

class Solution {
public:
    int reverse(int x) {
        if((x<10 && x>0) || (x >-10 && x<0)) return x;
		//for caculating convinence, convert it to numbers bigger than 0, and use flag to mark.
        bool flag = true;
        if(x<0){
            flag = false;
            x = x*(-1); //for now x is bigger than 0
        }
        
        string s = to_string(x);
        
        //caculate the reverse number		
        int result = 0;
        for(unsigned i=0; i<s.size(); i++){
            char c = s.at(i);
            int t = (int)c - 48;
           //cout<<"t"<<t<<endl;
            result += t* pow(10,i);
        }
		
		//normal result is bigger than 0, if result is overflow result is smaller than 0
        if(result <0) return 0;
		
		//use flag to judge if we should add a '-' to the result;
        if(flag) return result;
        else return result*(-1);
    }
};