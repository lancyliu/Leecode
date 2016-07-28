/*
 @ July 27 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  73. Set Matrix Zeroes
* 
    Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

    click to show follow up.

    Follow up:
    Did you use extra space?
    A straight forward solution using O(mn) space is probably a bad idea.
    A simple improvement uses O(m + n) space, but still not the best solution.
    Could you devise a constant space solution?


*/
	 

/**
use two list to store the rows and cols which contains zero element.
then according these two list change the element in matrix.
However, this method use O(m+n) space ??
*/
public class Solution {
    public void setZeroes(int[][] matrix) {
        List<Integer> rowz = new ArrayList<Integer>();
        List<Integer> colz = new ArrayList<Integer>();
        
        for(int i=0; i<matrix.length; i++){
            for(int j=0; j<matrix[0].length; j++){
                if(matrix[i][j] == 0){
                        rowz.add(i);
                        if( !colz.contains(j) ) colz.add(j);
                    }
                else continue;
               
            }
        }
        
        for(int i=0; i<rowz.size(); i++){
            int r = rowz.get(i);
            for(int j=0; j<matrix[0].length; j++) matrix[r][j] = 0;
        }
        
        for(int i=0; i < colz.size(); i++){
            int c = colz.get(i);
            for(int j=0; j<matrix.length; j++) matrix[j][c] = 0;
        }
        return;
    }
}