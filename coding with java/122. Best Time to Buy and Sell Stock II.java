/*
@ Feb 17 2017
@ by Xin Liu
*/

/************Description of the problem************/
/* 122. Best Time to Buy and Sell Stock II
*
 Say you have an array for which the ith element is the price of a given stock on day i.

 Design an algorithm to find the maximum profit. 
 You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times).
 However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/


public class Solution {
    public int maxProfit(int[] prices) {
        //use greedy algorithm to solve this question
        int max = 0;
        int i=1;
        while(i < prices.length){
            if(prices[i] > prices[i-1]){
                max += prices[i] - prices[i-1];
            }
            i++;
        }
        return max;
    }
}