/*
 @ July 15 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  17. Letter Combinations of a Phone Number
* 
    Given a digit string, return all possible letter combinations that the number could represent.

    A mapping of digit to letters (just like on the telephone buttons) is given below.
	
	For example:
	 Input:Digit string "23"
     Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

*/
	 

/**
Use a hash map to store the number and characters it matches.
Use the idea of backtracking
use recurrsion to implement it .
*/

public class Solution {
    public List<String> letterCombinations(String digits) {
        
        Map<Integer,String> myMap = new HashMap<Integer,String>();
        myMap.put(0," ");
        myMap.put(1,"");
        myMap.put(2,"abc");
        myMap.put(3,"def");
        myMap.put(4,"ghi");
        myMap.put(5,"jkl");
        myMap.put(6,"mno");
        myMap.put(7,"pqrs");
        myMap.put(8,"tuv");
        myMap.put(9,"wxyz");
        
        List<String> myList = new ArrayList<String>();
        if(digits == null || digits.length() == 0) return myList;
        else {
            //System.out.println("check point 1");
            String temp = new String();
            Combine(digits, myMap, myList, 0, "");
            return myList;
        }
    }
    
    public void Combine(String digits, Map<Integer, String> myMap, List<String> myList, int index, String temp){
        if(index == digits.length()){
            if(!temp.isEmpty()) myList.add(temp);
            return;
        }
        else{
            char c = digits.charAt(index);
            int t = (int)c - 48;
            Integer it = new Integer(t);
            String r = myMap.get(it);
            
            for(int i=0; i<r.length(); i++){
                String next = temp + r.charAt(i);  // this point we should construct a new string called next, not add on temp.
                Combine(digits, myMap, myList, index+1, next);
            }
        }
    }
}