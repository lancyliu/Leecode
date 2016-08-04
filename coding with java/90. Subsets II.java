/*
 @ Aug 3 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  90. Subsets II
* 
    Given a collection of integers that might contain duplicates, nums, return all possible subsets.

    Note: The solution set must not contain duplicate subsets.

    For example,
    If nums = [1,2,2], a solution is:

    [
      [2],
      [1],
      [1,2,2],
      [2,2],
      [1,2],
      []
    ]


*/
	 

/**
if n=2 :  00,  01,     11, 10
if n=3 :  000，001，011，010   110， 111，101，100 （add 0 befor former result, add 1 before reverse of former result.）
*/
public class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        List<Integer> temp = new ArrayList<Integer>();
        Arrays.sort(nums);
        result.add(temp);
        int number = 0;
        for(int i=0; i< nums.length; ++i){
            int limit = result.size();
            for(int j=0; j < limit; ++j){
                if(i ==0 || nums[i] != nums[i-1] || j >= number){
                    result.add(new ArrayList<Integer> (result.get(j)));
                    result.get(result.size()-1).add(nums[i]);
                    
                }
            }
            
            number = limit;
        }
        return result;
    }
}