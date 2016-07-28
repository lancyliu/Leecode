/*
 @ July 24 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  62. Unique Paths
* 
    A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

    The robot can only move either down or right at any point in time. 
    The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

    How many possible unique paths are there?


*/
	 

/**
There are two methos. however one method costs too much time.
Method 1: DP, use one 2D array to store the information.
s[i][j] = s[i-1][j] + s[i][j-1].
*/

public class Solution {
    public int uniquePaths(int m, int n) {
        //start from (0,0) to (m,n)
        /*
        int result =0;
        if(m==0 || n==0) return 0;
        result = findPath(m,n,0,0);
        return result;
        */
        int[][] result = new int[m][n];
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 || j==0) result[i][j]=1;
                else result[i][j] = result[i-1][j] + result[i][j-1];
            }
        }
        return result[m-1][n-1];
    }
    /**
    private int findPath(int m, int n, int curx, int cury){
        if(curx ==(m-1) && cury== (n-1)){
            return 1;
        }
        else if(curx == (m-1) && cury < (n-1)){
           // System.out.println("check point 1");
            return 1;
        } 
        else if(curx <(m-1) && cury ==(n-1)) return 1;
        else {
           // System.out.println("check point 3");
          return  findPath(m,n, curx+1, cury) + findPath(m,n,curx, cury+1);   
        }
    }
    */
}