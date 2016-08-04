/*
 @ July 28 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  78. Subsets
* 
    Given a set of distinct integers, nums, return all possible subsets.

    Note: The solution set must not contain duplicate subsets.

    For example,
    If nums = [1,2,3], a solution is:

    [
      [3],
      [1],
      [2],
      [1,2,3],
      [1,3],
      [2,3],
      [1,2],
      []
    ]


*/
	 

/**
 backtracking
*/
public class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        List<Integer> temp = new ArrayList<Integer>();
        
        if(nums.length ==0){
            result.add(new ArrayList<Integer>());
            return result;
        }
        else{
            result.add(new ArrayList<Integer>());
            getSub(nums, result, temp, 1, 0);
            return result;
        }
    }
    
    private void getSub(int[] nums, List<List<Integer>> result, List<Integer> temp, int number, int index){
        if(temp.size() == number){
            result.add(new ArrayList<Integer>(temp));
            return;
        }
        
        for(int i=index; i<nums.length; ++i){
            if(!temp.contains(nums[i])){ 
                temp.add(nums[i]);
                getSub(nums, result, temp, number, i+1);
                if(number < nums.length) getSub(nums, result,temp,number+1, i+1);
               temp.remove(temp.size()-1);
            }
        }
    }
}