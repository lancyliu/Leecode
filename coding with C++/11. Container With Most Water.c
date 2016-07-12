/*
 @ July 11 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  11. Container With Most Water
* 
    Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
	n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, 
	which together with x-axis forms a container, such that the container contains the most water.

    Note: You may not slant the container.

*/
	 

/**
Since this container may not slanted. the size of the container = min(ai,aj) *(j-i)
step 1: find the highest and lowest height. 
  Analysis: if height.at(i) == lowest height, then the result is decided by the index, just donsider the farthest point.
  if it not the lowest height. then scan the other point from tail(farthest one), and the index of this point should be no less than rightmost heightest point.
   (Why? 
     points in the right of rightmost heightest point have a bigger distance then rightmost heightest point, 
	 but points in the left of rightmost heightest point, have a smaller height and a smaller distance to the other point, it won't form a bigger continer)
step 2: start from index 0, the other point start from tail.
  scan each pair of point in the vector.
*/


class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int i=0;
        int result=0;
        int high=0; //height of result container.
        //find the heightest height in the vector.
        int heightest =0;
        int hest_index =0;
        
        int lowest =height.at(0);
        for(unsigned m=0; m< height.size(); m++){
            if(height.at(m) >heightest) {
                heightest = height.at(m);
                hest_index = m;
            }
            else if(height.at(m) == heightest && m>hest_index) hest_index = m; //hest_index is the rightmost index with highest height.
            
            if(height.at(m) < lowest) lowest = height.at(m);
        }
  
        //if element in index i == lowest, the maxArea will be dicided by the index.
        //for each index only need to process the elements that with index bigger than hest_index ??
        while(i<= hest_index/*height.size()*/){
            int h1 = height.at(i);
            
            if(h1 == lowest){
                int r = lowest * (size-i-1);
                if(r > result){
                   result = r;
                   high = lowest;
                }
                i++;
            }
            else if(h1 <= high) i++;
            else{
                
                int h2 = height.at(size-1);
            
                int h = min(h1,h2);
                int r = h*(size-i-1);
                if(r > result) {
                    result = r;
                    high = h;
                  }
            
                int j=size-2;
                while(j >= hest_index){
                   if(min(h1,height.at(j)) > high){
                      int r = min(h1,height.at(j)) * (j-i);
                      if(r>result) {
                          result = r;
                          high = min(h1,height.at(j));
                      }
                      j--;
                   }
                   else j--;
                }
                i++;
            }
        }
        return result;
    }
};