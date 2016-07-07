/*
 @ July 2 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 38. Count and Say
* 
   The count-and-say sequence is the sequence of integers beginning as follows:
   1, 11, 21, 1211, 111221, ...

   1 is read off as "one 1" or 11.
   11 is read off as "two 1s" or 21.
   21 is read off as "one 2, then one 1" or 1211.
   Given an integer n, generate the nth sequence.

   Note: The sequence of integers will be represented as a string.

*/
	 



/**
stores 1th, 2th,3th,....(n-1)th result in a vector.
according (n-1)th string to get tht nth result.
*/
	 
class Solution {
public:
    string countAndSay(int n) {
     vector<string> result;
	 
     if(n==0) return NULL;
     
     string t = "1";
     result.push_back(t);
    
    if( n>1){
         int m = 1;
         while(m<n){
			  //s is the (m-1)th result. according this we can get the mth result.
                 string s = result.at(m-1);
                 string temp;
                 unsigned i=0;
                 while(i<s.size()){
                    // for thie element,we should check the element behind it.
                     unsigned j=i+1;
                     int hz=1;
                     while(j<s.size()){
						 //if the element is the same, continue to find how much samiliar element.
						 //else break;
                         if(s.at(j) == s.at(i)) {
                             ++hz;
                             ++j;
                         }
                         else break;
                     }
					 //use hz to store how much simaliar element of s.at(i),if hz=1, no same behind i. we push 1, and s.at(i) into the result. 
                     if(hz==1){
                         temp.push_back('1');
                         temp.push_back(s.at(i));
                         i++;
                     }
                     else{
						 //if hz > 1, we should push hz, and s.at(i) into the result. 
						 //in this condition, i should plus hz.(to access the next not the same element)
                         char c = (char)hz + 48;
                         temp.push_back(c);
                         temp.push_back(s.at(i));
                         i = i+hz;
                     }
                 }
                 result.push_back(temp);
             m++;
         }
     }
     return result.at(result.size()-1);
    }
};