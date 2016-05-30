/*
 @ May 30 2016 Monday
 @ by Xin Liu 
*/

/**Description of the problem**/
/* LeetCode 283. Move Zeroes
* Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

* For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

* Note:
*  1. You must do this in-place without making a copy of the array.
*  2. Minimize the total number of operations.

*/


/*

*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       unsigned i = 0;
       int znum = 0;
	   //we add znum in loop condition. znum represents the number of zero in the nums. 
	   //since we already remove 0 to the tail. we do not need to cosider this part of item in nums.
        while(i < (nums.size() - znum)){
            if(nums.at(i) == 0){
                nums.erase(nums.begin() + i);
                nums.push_back(0);
                znum++;  // once we found one zero element, znum increased by one.
            }
            else{
                i++;
            }
        }
    }
};