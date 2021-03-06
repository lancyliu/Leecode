/*
@ Feb 17 2017
@ by Xin Liu
*/

/************Description of the problem************/
/* 116. Populating Next Right Pointers in Each Node
*
 Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }


*/


public class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        if(gas.length == 0 || cost.length ==0 ) return -1;
        int start = 0;
        while(start < gas.length){
            if(gas[start] < cost[start]) start++;
            else{
                int iterate = start+1;
                int residu = gas[start] - cost[start];
                if(iterate >= gas.length) iterate -= gas.length;
                boolean flag = true;
                while(iterate != start){
                    residu = residu + gas[iterate] - cost[iterate];
                    if(residu <0){
                        flag = false;
                        break;
                    }
                    iterate ++;
                    if(iterate >= gas.length) iterate -= gas.length;
                    
                }
                if(flag) return start;
                else start ++;
            }
        }
        return -1;
    }
}