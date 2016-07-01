/*
 @ Jun 26 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 165. Compare Version Numbers
* 
   Compare two version numbers version1 and version2.
   If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

   You may assume that the version strings are non-empty and contain only digits and the . character.
   The . character does not represent a decimal point and is used to separate number sequences.
   For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

   Here is an example of version numbers ordering:

   0.1 < 1.1 < 1.2 < 13.37

*/
	 


/*

*/
class Solution {
public:
//this function get first part of version, and then delete this first part in version.
//for example: input: version = 1.0.1  output:result = 1; version = 0.1;
   int getNumber(string *version){
       if(version->empty()) return 0;
       int result = 0; 
       int length = 0;
       for(unsigned i = 0; i < version->size(); i++){
           if(version->at(i) == '.')break;
           else{
               length++;
           }
       }
    
       for(int i=0; i<length;i++){
           char c = version->at(i);
           int temp = (int)c - 48;
           result += pow((double)10,length-1-i) * temp;
       }
       
       for(int i=0;i<length; i++){
           version->erase(version->begin());
       }
       if(!version->empty()) version -> erase(version->begin());  //this sentence is to delete the '.' in the string.
       return result;
   }
  int compareVersion(string version1, string version2) {
     
        if(version1.empty() && version2.empty()) return 0;
        else{
			// we pass address of version, so that getNumber function can change the value of version.
            int num1 = getNumber(&version1);   
          
            int num2 = getNumber(&version2);
           
            if(num1 < num2) return -1;
            else if(num1 > num2) return 1;
            else{
                return compareVersion(version1,version2);
            }
        }
  }
};