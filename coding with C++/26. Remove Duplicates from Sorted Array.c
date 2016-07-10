/*
 @ July 9 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 26. Remove Duplicates from Sorted Array
* 
    Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

    Do not allocate extra space for another array, you must do this in place with constant memory.

    For example,
     Given input array nums = [1,1,2],

    Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. 
	It doesn't matter what you leave beyond the new length.

*/
	 



/**
since the array is a sorted list, once the element behind i is not equal to i, we can break the second loop.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int size = nums.size();
        while(i<nums.size()){
            int temp = nums.at(i);
            int j=i+1;
            while(j< nums.size()){
                if(temp == nums.at(j)){
                    nums.erase(nums.begin()+j);
                }
                else break;
            }
            i++;
        }
        return nums.size();
    }
};