/*
 @ July 26 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  63. Unique Paths II
* 
    Follow up for "Unique Paths":

    Now consider if some obstacles are added to the grids. How many unique paths would there be?

    An obstacle and empty space is marked as 1 and 0 respectively in the grid.

    For example,
     There is one obstacle in the middle of a 3x3 grid as illustrated below.

     [
       [0,0,0],
       [0,1,0],
       [0,0,0]
     ]
    The total number of unique paths is 2.


*/
	 

/**

*/
public class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int r =obstacleGrid.length;
        int c = obstacleGrid[0].length;
        int[][] result = new int[r][c];
        
        for(int i=0; i<r; i++){
            for(int j=0; j<c; ++j){
                if(obstacleGrid[i][j] == 1) result[i][j] = 0;
                else if(i == 0 && j==0) result[i][j] = 1;
                else if(i ==0 && j!=0 ) result[i][j] = result[i][j-1];
                else if(i!=0 && j==0) result[i][j] = result[i-1][j];
                else{
                    result[i][j] = result[i-1][j] + result[i][j-1];
                }
            }
        }
        
        return result[r-1][c-1];
    }
}