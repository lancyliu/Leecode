/*
 @ Jun 25 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 168. Excel Sheet Column Title
* 
   Given a positive integer, return its corresponding column title as appear in an Excel sheet.

   For example:

      1 -> A
      2 -> B
      3 -> C
      ...
      26 -> Z
      27 -> AA
      28 -> AB 

*/
	 


/*
first store 'A--Z' in a vector. use ASCII code to transfer from int to char.
then, caculate correspoinding column title of n.
*/
class Solution {
public:
    string convertToTitle(int n) {
         vector<char> title;
        string result;
        for(int i = 0; i< 26; i++){
            char t = (char)i+65;
            title.push_back(t);
        }
        if(n <= 26){
			//if n is smaller than 26, directly return the index.
            result.push_back(title.at(n-1));
        }
        else
        {
			//if n i bigger than 26. loop: n = n /26 in each loop.
            string pre;
            int resi = 0;
            while( n > 26){
                resi = n %26;
                n = n / 26;
				//if resi is 0, since if n==26, result = Z, n==52 result = AZ, we can see that n should be -1 if resi is 0.
                if(resi != 0) pre.push_back(title.at(resi-1));
				else 
				{
					pre.push_back(title.at(25));
					n = n -1;
				}
            }
            /*if(resi !=0)*/ pre.push_back(title.at(n -1));
			//else pre.push_back(title.at(n-2));
            for(unsigned i = 0; i < pre.size(); i++){
                char temp = pre.at(pre.size() - 1 -i);
                result.push_back(temp);
            }
        }
        return result;
    }
};