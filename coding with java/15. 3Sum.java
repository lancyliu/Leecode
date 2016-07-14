/*
 @ July 13 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  15. 3Sum
* 
    Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
	Find all unique triplets in the array which gives the sum of zero.

    Note: The solution set must not contain duplicate triplets.

    For example, given array S = [-1, 0, 1, 2, -1, -4],

    A solution set is:
    [
      [-1, 0, 1],
      [-1, -1, 2]
    ]

*/
	 

/**
sort the array, and use three loops to scan the array.
However this method is slow. new method will be discussed in 16. 3Sum Cloest.
*/

public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        
        //Integer[] number = new Integer[nums.length];
        Integer[] number = IntStream.of( nums ).boxed().toArray( Integer[]::new );
        Arrays.sort(number);
        int i=0;
        while( i< number.length){
            Integer tx = number[i];
            if(tx >0) break;
            else if(tx ==0){
                if(i+2 < number.length && number[i]==0 && number[i+1]==0 && number[i+2]==0){
                    List<Integer> temp = new ArrayList<Integer>();
                    temp.add(0);
                    temp.add(0);
                    temp.add(0);
                    result.add(temp);
                    break;
                }
                else break;
            }
            else if( i!= 0 && (tx == number[i-1])) i++;
            else{
                int j=i+1;
                while(j < number.length){
                    Integer halfsum = number[i]+number[j];
                    if(j != i+1 && number[j] ==number[j-1]) j++;
                    else if(halfsum >0)break;
                    else{
                        int m=j+1;
                        while(m<number.length){
                            if(number[m]<0) m++;
                            else if(number[m] + halfsum > 0)break;
                            else if(m !=j+1 && number[m] == number[m-1]) m++;
                            else if(number[m]+halfsum == 0){
                                List<Integer> temp = new ArrayList<Integer>();
                                temp.add(number[i]);
                                temp.add(number[j]);
                                temp.add(number[m]);
                                result.add(temp);
                                m++;
                            }
                            else m++;
                        }
                        j++;
                    }
                }
                i++;
            } 
        }
        return result;
    }
    
}