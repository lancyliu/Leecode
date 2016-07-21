/*
 @ July 20 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  46. Permutations
* 
    Given a collection of distinct numbers, return all possible permutations.

    For example,
     [1,2,3] have the following permutations:
     [
      [1,2,3],
      [1,3,2],
      [2,1,3],
      [2,3,1],
      [3,1,2],
      [3,2,1]
     ]

*/
	 

/**
backtrack
*/

public class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        List<Integer> temp = new ArrayList<Integer>();
        
        permutations(nums, result, temp);
        return result;
    }
    
    private void permutations(int[] nums, List<List<Integer>> result, List<Integer> temp){
        if(temp.size() == nums.length){
            result.add(new ArrayList<Integer>(temp));
            return;
        }
        
        for(int i = 0; i<nums.length; i++){
            if(temp.contains(nums[i])) continue;
            else{
                temp.add(nums[i]);
                permutations(nums,result,temp);
                temp.remove(temp.size()-1);
            }
        }
    }
}