/*
 @ July 18 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  35. Search Insert Position
* 
    Given a sorted array and a target value, return the index if the target is found. 
	If not, return the index where it would be if it were inserted in order.

    You may assume no duplicates in the array.

    Here are few examples.
     [1,3,5,6], 5 → 2
     [1,3,5,6], 2 → 1
     [1,3,5,6], 7 → 4
     [1,3,5,6], 0 → 0

*/
	 

/**
use binary search search whether there exits target in array or not, and store the index of the target if exits.

*/

public class Solution {
    public int searchInsert(int[] nums, int target) {
        int left =0;
        int right = nums.length;
		
		//some special conditions:
        if(target > nums[nums.length -1]) return nums.length;
        else if(target < nums[0]) return 0;
        
        if(nums.length == 1){
            if(nums[0] >= target) return 0;
            else return 1;
        }
		
        //result == -1 means that target not exitst.
		//use binary search, according to comparation between target and nums[median], change the value of left/right.
        int result = -1;
        while(left < right){
            int median = (left + right)/2;
            if(left == right-1 && nums[left] != target && nums[right] != target) break;
            
            if(nums[median] == target) {
                result = median;
                break;
            }
            else if(nums[median] < target){
                left = median;
            }
            else right = median;
        }
        //if result ==-1, we should check out the insert position.
		//after former while loop, left may bigger than right, or left smaller than right.
        if(result == -1){
            if(left >= right){
                int j = right;
                while(j >=0 && nums[j] > target) j--;
                result = j+1;
            }
            else {
                int j = left;
                while(j < nums.length && nums[j] <target) j++;
                result = j;
            }
        }
        
        return result;
    }
}