/*
 @ Jun 27 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 121. Best Time to Buy and Sell Stock
* 
   Say you have an array for which the ith element is the price of a given stock on day i.

   If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), 
   design an algorithm to find the maximum profit.

   Example 1:
     Input: [7, 1, 5, 3, 6, 4]
     Output: 5

   max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
   Example 2:
     Input: [7, 6, 4, 3, 1]
     Output: 0

   In this case, no transaction is done, i.e. max profit = 0.

*/
	 


	 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       if(prices.empty() || prices.size() == 1) return 0;
       int n=1;
       int l = prices.size();
       int result=0;
       //delete the 0 in the end of vector.
       //delete the decreasing elements in the end of vector.
       //delte the decreasing elements in the beginning of vector.
       
       int index = l-1;
       while(index > 0){
           if(prices.at(index) == 0){
               prices.erase(prices.begin()+index);
               
           }
           else if(prices.at(index) <= prices.at(index-1)){
               prices.erase(prices.begin()+index);
           }
           else break;
           index = prices.size() - 1;
       }
     
       if(prices.empty() || prices.size() == 1) return 0;
       index = 0;
       while(index < prices.size()){
           
           if(prices.at(index) >= prices.at(index+1)) prices.erase(prices.begin());
           else break;
       }
       
       if(prices.empty() || prices.size() == 1) return 0;
	   
	   // suppose the distance between two days is 1,2,3,4,..... size -1.  
	   // find the maximum prices distance in each condition. pick the maximum one in these result.
       while(n <prices.size()){
           
           int max = 0;
          //cout<<n<<endl;
           for(unsigned i=0; i< prices.size()-n; i++){
               int temp = prices.at(i+n)-prices.at(i);
               if((temp >0) && (max < temp)){
                   max = temp;
                   //cout<<"i" <<i<<endl;
               }
           }
          //cout<<"max "<<max<<endl;
           if((n==1) && (max==0)) break;
           if(result < max) result = max;
           n++;
       }
       return result;
       
    }
};