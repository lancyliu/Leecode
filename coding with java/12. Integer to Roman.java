/*
 @ July 13 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  12. Integer to Roman
* 
    Given an integer, convert it to a roman numeral.

    Input is guaranteed to be within the range from 1 to 3999.

*/
	 

/**

*/


public class Solution {
    public String intToRoman(int num) {
        //number of 1000, number of 500, number of 100...
		//stroes the roman number in a hash map, the key is integer.
        Map<Integer,String> myMap = new HashMap<Integer,String>();
        myMap.put(1000,"M");
        myMap.put(500,"D");
        myMap.put(100,"C");
        myMap.put(50,"L");
        myMap.put(10,"X");
        myMap.put(5,"V");
        myMap.put(1,"I");
		
        //stores all the keys(in the hashmap) in an array 
        int[] numbers = new int[7];
        numbers[0] =1000;
        numbers[1] =500;
        numbers[2] =100;
        numbers[3] =50;
        numbers[4] =10;
        numbers[5] =5;
        numbers[6]=1;
        
        //
        String result = new String();
        int i=0;
		//while the input number bigger than zero and i represent index of array numbers.
        while(num >0 && i<7){
            int n = num/numbers[i];
            int resi = num % numbers[i];
            
			//if n==0, process the next element. Note that i = i+2, that is we only consider 1000, 100,10,1. according to n, we will use 50 if needed.
            if(n==0){
                i += 2;
                num = resi;
            }
            else if(n==4 && i!= 0){
				//if n==4, there will be "IV" pattern, 
                result += myMap.get(numbers[i]);
                result += myMap.get(numbers[i-1]);
            }
            else if(n==9 && i>1){
				//if n==9, there will be a "IX" pattern
             result = result + myMap.get(numbers[i]) + myMap.get(numbers[i-2]);
            }
            else if(n>4 && i!=0){
				//if n bigger than 4, then we need 500, 50, or 5.
                result += myMap.get(numbers[i-1]);
                for(int j=0; j< n-5;j++)
                 result += myMap.get(numbers[i]);
            }
            else {
				//else result of this position should be n times 1,10,100,1000 
                for(int j=0; j< n;j++)
                 result += myMap.get(numbers[i]);
            }
            
            num = resi;
        }
       return result;
    }
}