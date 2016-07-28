/*
 @ July 23 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  59. Spiral Matrix II
* 
    Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

    For example,
     Given n = 3,

     You should return the following matrix:
     [
      [ 1, 2, 3 ],
      [ 8, 9, 4 ],
      [ 7, 6, 5 ]
     ]


*/
	 

/**

*/

public class Solution {
    public int[][] generateMatrix(int n) {
        int[][] result = new int[n][n];
        
        generate(result, n, 1, 0,0);
        
        return result;
    }
    //index is row number , initial means start number in this condition.
    private void generate(int[][] result, int n, int direction, int index, int initial){
        int half = n/2;
        if(direction == 1){
            //while direction ==1, index must smaller than n/2 ?? 
            int start = index;
            int end = n-index-1;
            int j;
            for(j = start; j <= end; j++)
                result[index][j] = initial + j - start+1;
            
            // go down.
            //System.out.println(result[index][end]);
            for(j = start+1; j <= end; j++)
               result[j][end] = result[index][end] + j - start;
           // System.out.println(result[end][end]);      
           if(index >= half) return; 
           else generate(result, n, -1, n-index-1, result[end][end]);
        }
        else{
            int start = index-1;
            int end = n-index-1;
            //System.out.println(initial);
            int j;
            for(j = start; j>= end; j--)
               result[index][j] = initial + start -j +1;
            
            // go up.
            for( j = index -1; j >= n-index; j--)
               result[j][n-index-1] = result[index][end] + index -j;
            
            if(index <= half) return;   
            else generate(result, n, 1, n-index, result[n-index][end]);
            
        }
    }
}