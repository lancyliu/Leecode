/*
 @ July 21 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  49. Group Anagrams 
* 
    Given an array of strings, group anagrams together.

    For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
    Return:

    [
      ["ate", "eat","tea"],
      ["nat","tan"],
      ["bat"]
    ]
   Note: All inputs will be in lower-case.

*/
	 

/**
Ther are two methods. However method two cost too much time.
Method 1: use a hashtable to store the information.
scan each item in string array strs. for each string, sort the string. if the sorted string is a kay in hashtable store the string in hashtable value.
if not, store the sorted string as a key of hashtable and the original string as value.
*/

import java.util.Enumeration;
import java.util.Hashtable;

public class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        
        //Arrays.sort(strs);
        
        List<List<String>> result = new ArrayList<List<String>>();
        
        Hashtable<String, List<String>> myMap = new Hashtable<String, List<String>>();
        
        int i=0;
        while(i < strs.length){
            String temp = strs[i];
            char[] ch = temp.toCharArray();
            Arrays.sort(ch);
            temp = String.valueOf(ch);
            if(myMap.containsKey(temp)) myMap.get(temp).add(strs[i]);
            else{
                List<String> ml = new ArrayList<String>();
                ml.add(strs[i]);
                myMap.put(temp, ml);
            } 
            
            i++;
        }
        //the result we want stored in hashtable value. to extract the value in hashtable.
        Enumeration keys = myMap.keys();
        while(keys.hasMoreElements()){
            Object key = keys.nextElement();
            result.add(myMap.get(key));
        }
       return result;
    }


/**
Method 2:  scan the element in string array, compare it to the item in result list. if there exits a sublist are anagrams store string in that sublist
else add a new sublist in result list. 
*/
/**
        int i=0;
 
        List<List<String>> result = new ArrayList<List<String>>();
 
        if(strs.length == 0) return result;
        while(i < strs.length){
            String s = strs[i];
            Integer it = new Integer(s.length());
            if(result.size() == 0 ){
                List<String> templete = new ArrayList<String>();
                templete.add(s);
                result.add(templete);
                
                
            }
            else{
                
                int j=0;
                boolean flag = false;
     
                while(j < result.size()){
                String str = result.get(j).get(0);
                if(equals(str, s)){
                    result.get(j).add(s);
                    flag = true;
                    break;
                }
                else j++;
            }
            
            if(!flag) {
                List<String> templete = new ArrayList<String>();
                templete.add(s);
                result.add(templete);
            }
        }
        i++;
    }
    return result;
    }
*/
/***    
    private boolean equals(String s1, String s2){
        //while found one same element, remove it from tempelte string(s1).
        //after scan the string. if both string is empty, return true. if found not match or one is not empty return false.
        if(s1.length() != s2.length() ) return false;
        if(s1.equals(s2)) return true;
        int i=0;
        while(i < s2.length()){
            char c = s2.charAt(i);
            
            int t = s1.indexOf(c);
            if(t == -1) return false;
            else{
                String temp = new String();
                temp = s1.substring(0,t) + s1.substring(t+1);
                s1 = temp;
                i++;
            }
        }
        if(s1.isEmpty()) return true;
        else return false;
    }
*/    
}