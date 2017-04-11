/*
@ Feb 17 2017
@ by Xin Liu
*/

/************Description of the problem************/
/* 134. Gas Station
*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.

Subscribe to see which companies asked this question.
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