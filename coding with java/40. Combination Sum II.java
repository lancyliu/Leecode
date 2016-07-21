/*
 @ July 19 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  40. Combination Sum II
* 
    Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

    Each number in C may only be used once in the combination.

    Note:
      All numbers (including target) will be positive integers.
      The solution set must not contain duplicate combinations.
      For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
      A solution set is: 
     [
       [1, 7],
       [1, 2, 5],
       [2, 6],
       [1, 1, 6]
     ]

*/
	 

/**
back tracking

*/

public class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        List<Integer> element = new ArrayList<Integer>();
        Arrays.sort(candidates);
        
        //delete elements which is bigger than target.
        int j = candidates.length -1;
        if(target < candidates[0]) return result;
        while(j >=0){
            if(candidates[j] > target) j--;
            else break;
        }
        
        //candidates = candidates.subList(0, j+1);
        
        combin2(candidates, target,result, element,0);
        return result;
    }
    
    private void combin2(int[] candidates, int target, List<List<Integer>> result, List<Integer> element, int index){
        if(target == 0){
            result.add(new ArrayList<Integer>(element));
            return;
        }
        
        for(int i=index; i<candidates.length; i++){
             if(i != index && candidates[i] == candidates[i-1]) continue;
             if(target - candidates[i]>=0) { 
                element.add(candidates[i]);
                combin2(candidates, target-candidates[i], result, element, i+1);
                element.remove(element.size() - 1);
            }
            else return;
        }
    }
}