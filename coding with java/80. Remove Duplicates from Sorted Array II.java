/*
 @ July 29 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  80. Remove Duplicates from Sorted Array II
* 
    Follow up for "Remove Duplicates":
    What if duplicates are allowed at most twice?

    For example,
     Given sorted array nums = [1,1,1,2,2,3],

    Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. 
	It doesn't matter what you leave beyond the new length.


*/
	 

/**
use a new array to store the result, then copy it to input array. However this method may waste a lot space
*/
public class Solution {
    public int removeDuplicates(int[] nums) {
        int result =0;
        int[] number = new int[nums.length];
    
        int i=0;
        if(nums.length <= 2) return nums.length;
        while(i < nums.length){
            if( i < nums.length-1 && nums[i] == nums[i+1]){
                int j= i;
                int count = 1;
                for(j = i; j<nums.length-1; ++j){
                    if(nums[j] == nums[j+1]) count++;
                    else break;
                }
               
                int value = nums[i];
                i += count;
                if(count >= 2) count = 2;
                
                for(int x=0; x<count; x++) number[result +x] = value;
                result += count;
            }
            else {
                
                number[result] = nums[i];
                i++;
                result++;
                
            }
        }

        for(int y=0; y< result; y++){
            nums[y] = number[y];
        }
        return result;
    }
}