/*
 @ July 18 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  34. Search for a Range
* 
    Given a sorted array of integers, find the starting and ending position of a given target value.

    Your algorithm's runtime complexity must be in the order of O(log n).

    If the target is not found in the array, return [-1, -1].

    For example,
     Given [5, 7, 7, 8, 8, 10] and target value 8,
     return [3, 4].

*/
	 

/**
use binary search search whether there exits target in array or not, and store the index of the target if exits.
scan from the index to left and right.
*/

public class Solution {
    public int[] searchRange(int[] nums, int target) {
        //binary search??
        int[] result = new int[2];
        result[0] = -1;
        result[1] = -1;
        
        if(target > nums[nums.length-1] || target < nums[0]) return result;
        if(nums.length==0) return result;
        
        boolean found = false;
        int left =0;
        int right = nums.length;
        int index = 0;
        
        while(left <right){
            //this if statement is to avoid some dead looping.
            if(left == right-1 && nums[left] != target && nums[right] != target) break;
            int median = (left + right)/2;
            if(nums[median] < target){
                left = median;
            }
            else if(nums[median] > target){
                right = median;
            }
            else {
                found = true;
                index = median;
                break;
            }
        }
        
        if(found){
            int i = index;
            while(i>=0 && nums[i] == nums[index] ) i--;
            int j = index;
            while(j < nums.length && nums[j] == nums[index]) j++;
            result[0] = i+1;
            result[1] = j-1;
        }
        
        return result;
    }
}