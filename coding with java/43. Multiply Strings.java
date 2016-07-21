/*
 @ July 20 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  43. Multiply Strings
* 
    Given two numbers represented as strings, return multiplication of the numbers as a string.

    Note:
     The numbers can be arbitrarily large and are non-negative.
     Converting the input string to integer is NOT allowed.
     You should NOT use internal library such as BigInteger.

*/
	 

/**
start from the tail, multiply each digit in num1 and num2, use temp to store the curry.
however, while multiply num1[i] and num2[j], the result should store in string result[i+j](since we start from tail and store result from beginnig it should be
num1.length-1-i + num2.length-1-j). however, this result should be reverse to get the actual result.
*/

public class Solution {
    public String multiply(String num1, String num2) {
        
        String result = new String();
        int i=num1.length() - 1;
        int temp = 0; 
        result = "";
        if(num1.length() == 0 || num2.length() == 0){
            
            for(int x=0; x<num1.length()-1; x++) result += "0";
            for(int y=0; y<num2.length()-1; y++) result += "0";
            return result;
        }
      
        if(num1.equals("0") || num2.equals("0")) {
            //System.out.println("check");
            result = "0";
            return result;
        }
        
        while(i >= 0){
            int j = num2.length() -1;
            while(j >= 0){
                char c1 = num1.charAt(i);
                char c2 = num2.charAt(j);
                if(c1 == '0' || c2 == '0'){
                    //System.out.println("check ");
                    //System.out.println("check result1" + result);
                    
                    if(result.length() <= num1.length() -1 -i + num2.length() - 1-j && result.length() == 0) result = "0";
                    else if(result.length() <= num1.length() -1 -i + num2.length() - 1-j) {
                        result += temp;
                        temp = 0;
                    }
                    else{
                        //System.out.println("check 2");
                        char c = result.charAt(num1.length() -1 -i + num2.length() - 1-j);
                        int t = (int)c - 48;
                        t += temp;
                        if(t >=10){
                            temp = t/10;
                            t = t%10;
                            
                        }
                        else temp = 0;
                        char ch = (char)t;
                        String newresult = new String();
                        newresult = result.substring(0,num1.length() -1 -i + num2.length() - 1-j) + t + result.substring(num1.length() -1 -i+1 + num2.length() - 1-j, result.length());
                        result = newresult;
                        //System.out.println("check result" + result);
                      
                    }
                }
                else{
                    //System.out.println("check 3");
                    int t1 = (int)c1 - 48;
                    int t2 = (int)c2 - 48;
                    int r = t1 * t2 + temp;
                    if(result.length() <= (num1.length() -1 -i + num2.length() - 1-j)){
                        //System.out.println("check 3 result" + result);
                        if(r >= 10){
                          temp = r/10;
                          r = r%10;
                        }
                        else temp = 0;
                        
                        if(result.length() == 0) result = Integer.toString(r);
                        else result += r;
                     
                    }
                    else {
                       
                        char c = result.charAt(num1.length() -1 -i + num2.length() - 1-j);
                        int t = (int)c - 48;
                        r  = r+t;
                        if(r >= 10){
                            temp = r/10;
                            r = r%10;
                        }
                        else temp = 0;
                        char ch = (char)r;
                        String newresult = new String();
                        newresult = result.substring(0,num1.length() -1 -i + num2.length() - 1-j) + r + result.substring(num1.length() -1 -i + num2.length() - 1-j+1, result.length());
                        result = newresult;
                       
                    }
                    
                }
                j --;
            }
            if(temp != 0) result += temp;
            temp = 0;
            i--;
        }
        
        if(temp != 0) result += temp;
        
        
        //reverse
        int m=result.length()-1;
        String rt = new String();
        rt = "" + result.charAt(m);
        m--;
        while(m >=0){
            rt += result.charAt(m);
            m--;
        }
        return rt;
    }
    
}