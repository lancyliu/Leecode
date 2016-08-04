/*
 @ July 28 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  77. Combinations
* 
    Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

    For example,
     If n = 4 and k = 2, a solution is:

     [
      [2,4],
      [3,4],
      [2,3],
      [1,2],
      [1,3],
      [1,4],
     ]


*/
	 

/**
 backtracking
*/
public class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        List<Integer> comb = new ArrayList<Integer>();
        if(n==0 || k==0) return result;
        if(k >n) return result;
        getCombine(n,k, result,comb,1);
        return result;
    }
    
    private void getCombine(int n, int k, List<List<Integer>> result,List<Integer> comb,int index){
        if(comb.size() == k){
            result.add(new ArrayList<Integer>(comb));
            return;
        }
        
        for(int i=index; i<=n; ++i){
            if(!comb.contains(i)){ 
                comb.add(i);
                getCombine(n,k,result,comb,i +1);
                comb.remove(comb.size()-1);
            }
        }
    }
}