/*
 @ July 28 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  79. Word Search
* 
    Given a 2D board and a word, find if the word exists in the grid.

    The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. 
	The same letter cell may not be used more than once.

    For example,
     Given board =

     [
       ['A','B','C','E'],
       ['S','F','C','S'],
       ['A','D','E','E']
     ]
   word = "ABCCED", -> returns true,
   word = "SEE", -> returns true,
   word = "ABCB", -> returns false.


*/
	 

/**
 backtracking
*/
public class Solution {
    public boolean exist(char[][] board, String word) {
        int[][] visited = new int[board.length][board[0].length];
        for(int i=0; i<board.length; ++i){
            for(int j=0; j<board[0].length; ++j){
                if(board[i][j] == word.charAt(0)){
                    if( match(board, word, i,j, 0, visited)) return true;
                    //go up
                    //go down
                    //go left
                    //go right
                }
            }
        }
        return false;
    }
    
    private boolean match(char[][] board, String word, int i, int j, int index, int[][] visited){
        if(index == word.length()-1) return true;
        
            visited[i][j] = 1;
            //int m = index+1;
            if(i>0){
                //go up
                if(board[i-1][j] == word.charAt(index +1) && visited[i-1][j] != 1) 
                if(match(board, word, i-1, j, index +1, visited)) return true;
                
            }
            if(i < board.length-1){
               // go down
                if(board[i+1][j] == word.charAt(index+1) && visited[i+1][j] != 1){
                  if( match(board, word, i+1,j,index+1,visited) ) return true;  
                } 
                
            }
            if(j >0){
                //go left
                if(board[i][j-1] == word.charAt(index+1) && visited[i][j-1] != 1) 
                if( match(board, word, i, j-1, index+1,visited)) return true;
            }
            if(j < board[0].length -1){
                //go right
                if(board[i][j+1] == word.charAt(index+1) && visited[i][j+1] != 1) 
                if (match(board, word, i, j+1, index+1,visited)) return true;
            }
        // if all condition is not true, then this point doesn't work. return false, mark as unvisited.
         visited[i][j] = 0;
         return false;
    }
}