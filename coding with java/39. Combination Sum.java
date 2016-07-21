/*
 @ July 19 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  39. Combination Sum
* 
    Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

    The same repeated number may be chosen from C unlimited number of times.

    Note:
     All numbers (including target) will be positive integers.
     The solution set must not contain duplicate combinations.
     For example, given candidate set [2, 3, 6, 7] and target 7, 
     A solution set is: 
     [
       [7],
       [2, 2, 3]
     ]

*/
	 

/**
back tracking

*/

public class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
       // int number = 1;
        //int curSum = 0;
        List<Integer> curList = new ArrayList<Integer>();
        
        //sort array, if element bigger than target, delete it. ??
        Arrays.sort(candidates);
        combine(candidates, target, result, curList,0);
        return result;
    }
    
    /**
     * result is result list, curList is one list may or may not in result; curSum is the sum of curList, . index stores which element we are processing.
    */
    private void combine(int[] candidates, int target, List<List<Integer>> result, List<Integer> curList,int index){
        
        if(target == 0){
            result.add(new ArrayList<Integer>(curList)); // must use new ArrayList, or the result will be empty. why ??
            return;
        }
   
            for(int i=index; i< candidates.length; i++){
                if(target - candidates[i] < 0) return;
                else{
                    curList.add(candidates[i]);
                    combine(candidates, target - candidates[i], result, curList, i);
                    curList.remove(curList.size() - 1);
                }
            }
    
    }
}