/*
 @ July 21 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  53. Maximum Subarray 
* 
    Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

    For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
     the contiguous subarray [4,−1,2,1] has the largest sum = 6.


*/
	 

/**

*/

public class Solution {
    public int maxSubArray(int[] nums) {
        
        int result = nums[0];
        int sum = 0;
        for(int i=0; i< nums.length; i++){
            sum += nums[i];
            if(sum > result) result = sum;
            if(sum < 0) sum =0;
        }
        
        return result;
    }
/**
       int result = nums[0];
       
       //scan the array find the biggest sigle item in array.
       boolean negative = true;  //true means all element in array is negative.
       for(int i=0; i<nums.length; i++){
           if(nums[i] > result) result = nums[i];
           if(nums[i] > 0) negative = false;
       }
       
       
       //if nagative == true, then the biggest sigle element will be the result.
       if(negative) return result;
       else{
           //scan each element, find the biggest subarray start from that element.
           int i=0;
           while(i < nums.length){
               if(nums[i] <= 0) i++;
               else{
                   int j=i+1;
                   int sum = nums[i];
                   while( j<  nums.length){
                       sum += nums[j];
                       if(sum > result) result = sum;
                       j++;
                   }
                   i++;
               }
           }
           return result;
       }
           
       }
       
*/       
}