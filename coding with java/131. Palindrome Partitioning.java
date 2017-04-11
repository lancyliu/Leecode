/*
@ Feb 17 2017
@ by Xin Liu
*/

/************Description of the problem************/
/* 131. Palindrome Partitioning
*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]

*/


public class Solution {
    public List<List<String>> partition(String s) {
        //1. partion the string, check each part is palindrome or not.
        //or 2. find first palindrome, sencond ....
        List<List<String>> result = new ArrayList<List<String>>();
        List<String> temp = new ArrayList<String>();
        
        FindPal(result,temp,s,0);
        return result;
    }
    
    public void FindPal(List<List<String>> result, List<String> temp,String s,int index){
        //if(num > s.length()) return;
        if(index == s.length()){
            result.add(new List<String>(temp));
            //temp.clear();
            return;
        }
        
        for(int i=index; i< s.length; i++){
            
        }
        
    }
}