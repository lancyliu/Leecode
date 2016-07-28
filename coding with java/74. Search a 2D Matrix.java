/*
 @ July 27 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  74. Search a 2D Matrix
* 
    Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.
    For example,

    Consider the following matrix:

    [
      [1,   3,  5,  7],
      [10, 11, 16, 20],
      [23, 30, 34, 50]
    ]
    Given target = 3, return true.


*/
	 

/**
use twice binary search to find target. 
However, we also can use one binary search, the variable is (left,right, up,down), this method should be faster.
*/
public class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int row = matrix.length;
        int col = matrix[0].length;
        if(target < matrix[0][0] || target > matrix[row-1][col-1]) return false;
        //if matrix only contain one element.
        if(row ==1 && col ==1){
            if(matrix[0][0] == target) return true;
            else return false;
        }
        
        //use binary search find which row the target belong.
        int left = 0;
        int right = row-1;
        while(left < right){
            int median = left+ (right - left)/2 ;
            if(right == left +1 && target>matrix[left][0] && target < matrix[right][0]) break;
            else if(right == left+1 &&(target == matrix[left][0] || target == matrix[right][0])) return true;
            else if(right == left+1 && target > matrix[right][0]){
                left = right;
                break;
            }
            else if(right == left+1) return false;
            else if(target > matrix[median][0]) left = median;
            else if(target < matrix[median][0]) right = median;
            else if(target == matrix[median][0]) return true;
            else return false;
            
        }
        
        //target should be in row left
        if(target > matrix[left][col-1]) return false;
       
        //use binary search find target in matrix[left].
        
        int l = 0;
        int r = col-1;
        while(l < r){
            int median =l+ (r -l)/2;
            if(r ==l+1 && (target == matrix[left][l] || target == matrix[left][r]) ) return true;
            else if( r== l+1) return false;
            else if(target > matrix[left][median]) l = median;
            else if(target < matrix[left][median]) r = median;
            else if(target == matrix[left][median]) return true;
            else return false;
        }
        return false;
    }
}