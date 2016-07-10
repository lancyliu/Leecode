/*
 @ July 9 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 27. Remove Element
* 
    Given an array and a value, remove all instances of that value in place and return the new length.

    Do not allocate extra space for another array, you must do this in place with constant memory.

    The order of elements can be changed. It doesn't matter what you leave beyond the new length.

    Example:
      Given input array nums = [3,2,2,3], val = 3

      Your function should return length = 2, with the first two elements of nums being 2.

*/
	 



/**

*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        while(i<nums.size()){
			//if nums.at(i) == val, remove this element in vector, if not, i++, scan next element in vector.
            if(nums.at(i) == val){
                nums.erase(nums.begin()+i);
            }
            else ++i;
        }
        
        int l = nums.size();
        return l;
    }
};