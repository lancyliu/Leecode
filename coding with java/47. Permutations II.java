/*
 @ July 20 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  47. Permutations II
* 
    Given a collection of numbers that might contain duplicates, return all possible unique permutations.

    For example,
     [1,1,2] have the following unique permutations:
     [
       [1,1,2],
       [1,2,1],
       [2,1,1]
     ]

*/
	 

/**
backtrack.
use a list used to store the element that is already been used.
*/

public class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        if(nums.length == 0) return result;
       
        List<Integer> temp = new ArrayList<Integer>(); 
        if(nums.length == 1){
            temp.add(nums[0]);
            result.add(temp);
            return result;
        }
        Arrays.sort(nums);
        List<Integer> used = new ArrayList<Integer>();
        permutations(nums, result, temp,used);
        return result;
    }
    
     private void permutations(int[] nums, List<List<Integer>> result, List<Integer> temp, List<Integer> used){
        if(temp.size() == nums.length){
            //if(!result.contains(temp))
               result.add(new ArrayList<Integer>(temp));
            // used.clear();
            return;
        }
        
        for(int i = 0; i<nums.length; i++){
            if(i != 0 && used.contains(i-1) && nums[i] == nums[i-1]) continue;
            
            if(used.contains(i)) continue;
            else{
              // if(used.size() >0) System.out.println("check " + used.get(0) + "  "+ used.get(used.size() -1));
                temp.add(nums[i]);
                used.add(i);
                permutations(nums,result,temp,used);
                temp.remove(temp.size()-1);
                used.remove(used.size() -1);
            }
        }
    }
}