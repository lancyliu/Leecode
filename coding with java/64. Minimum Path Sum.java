/*
 @ July 27 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  64. Minimum Path Sum
* 
    Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 
    Note: You can only move either down or right at any point in time.


*/
	 

/**
At each point, the sum of path is added by the point up or left, thus pick the minimum point then plus the current point, is the min path sum of this point

use a 2-D array to store the minimum path sum of each point in the grid.
*/
public class Solution {
    public int minPathSum(int[][] grid) {
        int r = grid.length;
        int c = grid[0].length;
        
        int[][] result = new int[r][c];
        
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                if(i ==0 && j==0) result[i][j] = grid[0][0];
                else if(i==0 && j!=0) result[i][j] = result[i][j-1] + grid[i][j];
                else if(i!=0 && j==0) result[i][j] = result[i-1][j] + grid[i][j];
                else{
                    int min = Math.min(result[i-1][j], result[i][j-1]);
                    result[i][j] = min + grid[i][j];
                }
            }
        }
        
        return result[r-1][c-1];
    }
}