/*
 @ July 18 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  31. Next Permutation
* 
    Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

    If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

    The replacement must be in-place, do not allocate extra memory.

    Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
     1,2,3 → 1,3,2
     3,2,1 → 1,2,3
     1,1,5 → 1,5,1

*/
	 

/**
how to improve the speed?
1. use binary search
2. do not need sort, just swap the value since we just want to transfer between asending order and descending order.

*/

public class Solution {
    public void nextPermutation(int[] nums) {
        /**
         * step 1. scan from tail, find the first element that is bigger then the former(index) one. thant is nums(i)>nums(i-1).
         *     however, if the array is descending order, this is to say the permutation is highest possible order. then we should change it to a asending order (lowest possible order).
         * 
         * step 2. use the index i we found in step 1. however, we should switch nums(i-1) with one element which is the smallest element that is bigger than nums(i-1).  After switch, we should sorted the elements from i--end to an asending order.
        */
         
         //flag is to judge whether the array is desending or not.
         //false means descending, true means not.
         boolean flag = false;
         
         int index = nums.length -1;
         while(index >0){
             if(nums[index] > nums[index -1]){
                 flag = true;
                 break;
             }
             else index--;
         }
         index = index -1;
         
         if(!flag){
             Arrays.sort(nums);
             return;
         }
         else{
             System.out.println("index  " +index);
             //however we can infer that nums[index+1] -- nums[nums.length -1] is descending order.
             int j = nums.length-1;
             while(j > index && nums[j] <= nums[index]) j--;
             //switch
             
             int temp = nums[j];
             nums[j] = nums[index];
             nums[index] = temp;
             
             //sort index+1 ---nums.length-1
             Arrays.sort(nums,index+1, nums.length);
            return; 
         }
    }
}