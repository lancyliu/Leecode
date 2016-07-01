/*
 @ Jun 28 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 118. Pascal's Triangle
* 
   Given numRows, generate the first numRows of Pascal's triangle.

   For example, given numRows = 5,
   Return

  [
         [1],
        [1,1],
       [1,2,1],
      [1,3,3,1],
     [1,4,6,4,1]
  ]

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
};