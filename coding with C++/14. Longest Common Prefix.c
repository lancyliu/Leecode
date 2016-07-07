/*
 @ July 2 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 14. Longest Common Prefix
* 
   Write a function to find the longest common prefix string amongst an array of strings.

*/
	 



/**

*/
	 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs){
        //if vector is empty or if vector only contain one element, just return.
		string result;
        if(strs.empty()) return result;
        if(strs.size() == 1) return strs.at(0);
        
		//use maclength to store the length of the result.
        int maxlength = 0;
        int index =0;
        
		//scan the element in strs.at(0), from index 0~~size.
        while(index <strs.at(0).size()){
            char c = strs.at(0).at(index);
            //count: how many string have the same prefix like strs.at(0). only if count == strs.size(), the prefix should be considered.
            int count = 0;
            for(unsigned j=1; j<strs.size(); j++){
                
                if(strs.at(j).size() <= index) break;
                else if(strs.at(j).at(index) == c){
                   
                    count++;
                }
                else break;
            }
            if(count == strs.size()-1){
               
                maxlength++;
                index++;
            } 
            else break;
        }
        
        result = strs.at(0).substr(0, maxlength);
        return result;
   }

/**
Following codes is to find a pair of string which have the longest common prefix in a group of strings.
*/
/**
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return NULL;
        if(strs.size() == 1) return strs.at(0);
        int index =0;
        int maxlength = 0;
        string result;
        while(index < strs.size()){
            string s = strs.at(index);
            int m = index+1;
            while(m<strs.size()){
                if(strs.at(m).at(0) == strs.at(index).at(0)){
                    int length = getLengthofCP(strs.at(m), strs.at(index));
                    if(length > maxlength){
                       result = strs.at(index);
                       maxlength = length;
                     }
                     strs.erase(strs.begin() +m);
                }
                else{
                    m++;
                }
            }
            index++;
        }
        
        string r = result.substr(0,maxlength);
        return r;
    }
    
    int getLengthofCP(string s, string t){
        if(s.empty() || t.empty()) return 0;
        else{
            int i=0;
            int j=0;
            while(i<s.size() && j<t.size()){
                if(s.at(i) == t.at(j)){
                    i++;
                    j++;
                }
                else break;
            }
            return i;
        }
    }
*/
};