/*
 @ July 30 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  81. Search in Rotated Sorted Array II
* 
    Follow up for "Search in Rotated Sorted Array":
    What if duplicates are allowed?

    Would this affect the run-time complexity? How and why?

    Write a function to determine if a given target is in the array.


*/
	 

/**

*/
public class Solution {
    public boolean search(int[] nums, int target) {
        int left = 0;
        int right = nums.length-1;
        
        int i=0;
        while(left <= right){
            int median = left+ (right - left)/2;
            if(nums[median] == target) return true;
            if(nums[median] < nums[right]){
                if(nums[median] < target && target <= nums[right]){
                    left = median+1;
                }
                else right = median -1;
            }
            else if(nums[median] > nums[right]){
                if(nums[median] >target && target >= nums[left]) right = median-1;
                else left = median +1;
            }
            else right --;
        }
        return false;
    }
}