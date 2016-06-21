/*
 @ Jun 21 2016 Monday
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 205. Isomorphic Strings
* 
   Given two strings s and t, determine if they are isomorphic.

   Two strings are isomorphic if the characters in s can be replaced to get t.

   All occurrences of a character must be replaced with another character while preserving the order of characters. 
   No two characters may map to the same character but a character may map to itself.

  For example,
       Given "egg", "add", return true.

       Given "foo", "bar", return false.

       Given "paper", "title", return true.

  Note:
     You may assume both s and t have the same length.
*/
	 



class Solution {
public:
    bool isIsomorphic(string s, string t) {
       int l = s.length();
        if(s.compare(t) == 0) return true;
		
        // store the flag whether thie element already been replaced in s.
        vector<bool> flag (l, false);
		
        for(int i=0; i < l; i++)
        {
            string subt = t.substr(0,i);
            size_t found = subt.find(t.at(i));
            // if the subarray of t already contains the element, then we do not need to consider it again.
			if(found != string::npos) continue;
            else
            {
                char temp = t.at(i);
                char stemp = s.at(i);
                for(int j = i; j < l; j++)
                {
					if(s.at(j) == stemp && flag.at(j) == false) 
					{
					   s.replace(s.begin()+j,s.begin()+j+1,1,temp);
					   flag.at(j) = true; // change the flag.
					}
                }
                
            }
            if(s.compare(t) == 0) break;

        }     
        if(s.compare(t) == 0) return true;
        else return false;
    }
};