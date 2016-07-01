/*
 @ Jun 28 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 119. Pascal's Triangle II
* 
   Given an index k, return the kth row of the Pascal's triangle.

   For example, given k = 3,
   Return [1,3,3,1].

   Note:
   Could you optimize your algorithm to use only O(k) extra space?

   Subscribe to see which companies asked this question

*/
	 


	 
class Solution {
public:
     vector<vector<int>> generate(int numRows) {
       //if(numRows == (long)0 ) return NULL;
       
        vector<vector<int>> result;
        int i=1;
        while(i<=numRows){
            vector<int> currentRow;
            for(int j=0; j<i; j++){
                if((i>2) && (j != 0 && j != i-1) ) {
                
                   int temp = result.at(i-2).at(j-1) + result.at(i-2).at(j);
                   currentRow.push_back(temp);
                   
                }
                else currentRow.push_back(1);
            }
            result.push_back(currentRow);
            i++;
        }
        return result;
    }
    
    vector<int> getRow(int rowIndex) {
       vector<int> row;
  
    
        vector<vector<int>> result = generate(rowIndex+1);
        
        row = result.at(rowIndex);
        return row;
    
    }
    
       
};