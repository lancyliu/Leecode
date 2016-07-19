/*
 @ July 16 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  22. Generate Parentheses
* 
    Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

    For example, given n = 3, a solution set is:

   [
     "((()))",
     "(()())",
     "(())()",
     "()(())",
     "()()()"
   ]

*/
	 

/**

*/

public class Solution {
    public List<String> generateParenthesis(int n) {
        
        //1. generate all possible combination
        //2. check if it well-formed
        //3. get the result
        
        char[] par = new char[2];
        par[0] = '(';
        par[1] = ')';
        
        int n0 = n;
        int n1 = n;
        String first = new String();
        for(int i=0; i< n; i++){
            first += "0";
        }
        for(int i=0; i<n; i++){
            first += "1";
        }
        String finalsign = new String();
        for(int i=0; i<n; i++){
            finalsign += "1";
        }
        for(int i=0; i<n-1; i++){
            finalsign += "0";
        }
        finalsign += "1";
        
        //String pattern = Integer.toString(n,2);
        List<String> result = new ArrayList<String>();
        generateAll(n, first, par, result,finalsign);
        return result;
        
    }
    
    private void generateAll(int n, String pattern, char[] parenthesis, List<String> result, String stopsign){
        
        while(!pattern.equals(stopsign)){
            //generate the parenthesis type according to the pattern.
            String formParen = new String();
            if(pattern.length() < 2*n){
               for(int j=0; j< 2*n - pattern.length(); j++) formParen += parenthesis[0];
            }
            int i=0;
            while(i< pattern.length()){
               char c = pattern.charAt(i);
               int t = (int)c - 48;
               formParen += parenthesis[t];
               i++;
             }
             
             //if this parenthesis pattern is legal, add it to the result
             if(isLegal(formParen)) result.add(formParen);
             
             
             //cal next partten
             Integer in = Integer.valueOf(pattern, 2);
             in += 1;
             String next = Integer.toString(in,2);
             pattern = next;
        }
        
        return;
        
    }
    
    private boolean isLegal(String s){
        //System.out.println(s);
        int i=0;
        while(i<s.length() && i>= 0){
            //System.out.println("inner s " + s);
            char c = s.charAt(i);
            if(c == '(' && i+1 < s.length() && s.charAt(i+1) == ')'){
                String str = s.substring(0,i) + s.substring(i+2);
                s = str;
            }
            else if (c == '(' && i+1 >= s.length()) return false;
            else if(c == '(' && s.charAt(i+1) == '(') i++;
            else if(c == ')' && i != 0 && s.charAt(i-1) == '(') {
                String str = s.substring(0,i-1) + s.substring(i+1);
                s = str;
                i = i-1;
            }
            else return false;
        }
        if(s.isEmpty()) return true;
        else return false;
    }
}