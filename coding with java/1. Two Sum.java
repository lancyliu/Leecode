/*
 @ July 12 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 1. Two Sum
* 
   Given an array of integers, return indices of the two numbers such that they add up to a specific target.

   You may assume that each input would have exactly one solution.

   Example:
    Given nums = [2, 7, 11, 15], target = 9,

    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1].
   UPDATE (2016/2/13):
    The return format had been changed to zero-based indices. Please read the above updated description carefully

*/
	 



/**
use hash map tp solve the problem.
for each element in nums, scan the hashmap, if there are any element equals target - current-item, then return result
else put this element into the hashmap.
By this way, we can find the result in o(n) times.
*/
	 
import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int[] twoSum(int[] nums, int target) {
        int length = nums.length;
        int [] result = new int[2];
        result[0] = 0;
        result[1] = 0;
        
        if(nums.length <=1) return result;
        else{
    
            Map<Integer,Integer> myMap = new HashMap<Integer,Integer>();
            int i=0;
            while(i<nums.length){
            Integer key = new Integer(nums[i]);
            Integer index = new Integer(i);
            
            if(myMap.containsKey(target-key)){
            	result[0] = myMap.get(target-key);
            	result[1] = i;
            	break;
            }
            else{
            	myMap.put(key, index);
            	i++;
            }
            }
            return result;
        }
    }
    
}