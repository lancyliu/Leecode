/*
 @ May 30 2016 Monday
 @ by Xin Liu 
*/

/**Description of the problem**/
/* LeetCode 290. Word Pattern
* Given a pattern and a string str, find if str follows the same pattern.

* Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
* pattern = "abba", str = "dog cat cat dog" should return true.
* pattern = "abba", str = "dog cat cat fish" should return false.
* pattern = "aaaa", str = "dog cat cat dog" should return false.
* pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
* You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.

*/


/*
we store each word in str into a string type vector called change.
then we can access each element in change by index i which is the same as pattern.
*/
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        
        vector<string> change;
        size_t found = str.find(" ");
        string sub_str;
        size_t previous;
		// construct the vector change...
        if(found != string::npos)
        {
           sub_str = str.substr(0, found);
           change.push_back(sub_str); 
        }
        else
		{
			change.push_back(str);
		}
           
        while(found != string::npos)
        {
            previous = found;
           found = str.find(" ", found+1);
           sub_str = str.substr(previous+1, found-previous-1);
           change.push_back(sub_str); 
           
        }
        if(change.size() != pattern.size()) return false;
		
        //for now we store the str into a vector .
        for(unsigned i = 0; i < pattern.length(); i++){
            size_t found2 = pattern.find(pattern.at(i));
            if(found2 != string::npos){
                if(found2 < i)
                {
					// there is a same element before i, we should check whether the element in change is match. 
				    //elements before i is already been checked, so we only need to check once.
                    if(change.at(i).compare(change.at(found2)) != 0) return false;
                }
                else
                {
                    //no same befor i, then i'th should different from all the item before it.
                    for(unsigned j = 0; j < i; j ++){
                        if(change.at(j).compare(change.at(i)) == 0) return false;
                    }
                }
            }
        }
            return true;

    }
};