/*
@ Feb 17 2017
@ by Xin Liu
*/

/************Description of the problem************/
/* 130. Surrounded Regions
*
 Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/


public class Solution {
    public void solve(char[][] board) {
       if(board == null || board.length == 0) return;
       //char[][] temp = board.clone();
      // System.out.println("check");

       
       for (int i = 0; i < board.length; i ++) {
            bfs(board, i, 0);
            bfs(board, i, board[i].length - 1);
        }
        for (int j = 0; j < board[0].length; j ++) {
            bfs(board, 0, j);
            bfs(board, board.length - 1, j);
        }
       
       
       for(int m=0; m<board.length; m++){
           for(int n=0; n<board[m].length; n++){
               if(board[m][n] == 'Y') board[m][n] = 'O';
               else board[m][n] = 'X';
           }
       }
       
    }
    
    public void bfs(char[][] board, int i, int j){
        Queue<Integer> qx = new LinkedList<Integer>();
        Queue<Integer> qy = new LinkedList<Integer>();
        qx.add(i);
        qy.add(j);
        
        if(board[i][j] != 'O') return;
        else board[i][j] = 'Y';
        
        while(qx.size() > 0){
            //System.out.println("check");
            int x = qx.poll();
            int y = qy.poll();
            
            
            if(x>0 && board[x-1][y] == 'O'){
                qx.add(x-1);
                qy.add(y);
                board[x-1][y] = 'Y';
            }
            
            if(x<board.length-1 && board[x+1][y] == 'O'){
                qx.add(x+1);
                qy.add(y);
                board[x+1][y] = 'Y';
            }
            
            if(y>0 && board[x][y-1] == 'O'){
                qx.add(x);
                qy.add(y-1);
                board[x][y-1] = 'Y';
            }
            
            if(y<board[0].length-1 && board[x][y+1] == 'O'){
                qx.add(x);
                qy.add(y+1);
                board[x][y+1] = 'Y';
            }
        }
    }
    
}