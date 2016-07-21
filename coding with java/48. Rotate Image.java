/*
 @ July 20 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  48. Rotate Image
* 
    You are given an n x n 2D matrix representing an image.

    Rotate the image by 90 degrees (clockwise).

    Follow up:
      Could you do this in-place?

*/
	 

/**
draw a picture, its easy to see the connection between new matrix and old matrix.
*/

public class Solution {
    public void rotate(int[][] matrix) {
        //not in place
        int row = matrix.length;
        int cols = matrix[0].length;
        int[][] newmatr = new int[cols][row];
        
        int i =0;
        int j=0;
        while(i<row){
            j=0;
            while(j < cols){
                newmatr[i][j] = matrix[row-j-1][i];
                j++;
            }
            i++;
        }

    
        for(i=0; i<row; i++){
            for(j=0; j<cols; j++) matrix[i][j] = newmatr[i][j];
        }
    
        return;
    }
}