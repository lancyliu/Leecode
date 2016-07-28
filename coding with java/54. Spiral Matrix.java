/*
 @ July 21 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  54. Spiral Matrix 
* 
    Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

    For example,
     Given the following matrix:

     [
      [ 1, 2, 3 ],
      [ 4, 5, 6 ],
      [ 7, 8, 9 ]
     ]
    You should return [1,2,3,6,9,8,7,4,5].


*/
	 

/**

*/

public class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        
        List<Integer> result = new ArrayList<Integer>();
        if(matrix.length ==0) return result;
        else if(matrix[0].length == 0) return result;
        
        next(matrix, result, 1, 0);
        return result;
    }
    //direction == 1 means forwared , == -1 means backward.
    //index is the current row.
    private void next(int[][] matrix, List<Integer> result, int direction, int index){
        int row = matrix.length;
        int cols = matrix[0].length;
        int temp = row/2;
        
        
        if(direction == 1){

            int begin, end;
            begin = index;
            end = cols - index-1;
          
           if(end < begin) return;
            for(int i=begin; i<= end; i++){
                result.add(matrix[index][i]);
            }
     
            for(int i= index+1; i < row-index; i++){
                    result.add(matrix[i][end]);
            }
              
            if(index == temp) return;
            else  next(matrix, result, -1, row-1-index);
        }
        else{
            //direction ==-1, backward.
            
            int end,begin;
            begin = row-index-1;
            end = cols - (row-index) -1;
            
            if(begin > end) return;
            for(int i=end; i>=begin; i--){
                result.add(matrix[index][i]);
            }
                //go up
            for(int i= index-1; i > row-1-index ; i--){
                result.add(matrix[i][row-1-index]);
               }
   
            if(index == temp) return;
            else  next(matrix, result, 1, row-index);
        }
    }
}