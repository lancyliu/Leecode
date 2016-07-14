/*
 @ July 14 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  16. 3Sum Closest
* 
    Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
	Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

*/
	 

/**
Same method as 3 sum.
use two loops: The outer loop start from index 0, then inner loop scan remainning array.
for inner loop: there are two variable: one is from head, the other from tail.
while 3 sum equals the result we can break the while 
else while if it smaller than current result, update the result.
according to the value of 3sum, move head and tail pointer.
*/

public class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int distance = -1; //smaller than 0 means that we didn't calculate it yet.
        int result = -1;
        int i=0;
        Arrays.sort(nums);
        while(i<nums.length-1){
           if(distance == 0) break;    
           else if(i !=0 && nums[i] == nums[i-1]) i++;
           else if(distance != -1 && distance + Math.abs(target) < nums[i]) break;
           else{
               int j= i+1;
               int m = nums.length-1;
               while(j < m){
                   int sum = nums[i] + nums[j] + nums[m];
                   if(sum == target){
                       result = target;
                       distance = 0;
                       break; //break the whole loop.
                   }
                   else if(Math.abs(sum-target) < distance || distance == -1){
                       distance = Math.abs(sum-target);
                       result = sum;
                   }
                   
                   if(sum > target) m--;
                   else j++;
               }
               i++;
           }
        }
        return result;
    }
}