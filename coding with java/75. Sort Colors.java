/*
 @ July 28 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  75. Sort Colors
* 
    Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, 
	with the colors in the order red, white and blue.

    Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

    Note:
     You are not suppose to use the library's sort function for this problem.

    click to show follow up.

    Follow up:
     A rather straight forward solution is a two-pass algorithm using counting sort.
     First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

     Could you come up with an one-pass algorithm using only constant space?


*/
	 

/**
use two variable represent the range of red, white, blue.  while the color do not in the right range, swap and change the range.
*/
public class Solution {
    public void sortColors(int[] nums) {
        int r =0; //range of red is 0---r. not include index i!!
        int w =0; //range of white is r --w not include index w.
        
        int i=0;
        while(i < nums.length){
            if(nums[i] == 0){
                if(i == r) { 
                    i++;
                    if(w==r) w++;
                    r++;
                }
                else{
                    //swap index r with index i??
                    int temp = nums[r];
                    nums[r] = nums[i];
                    nums[i] = temp;
                    if(w==r) w++;
                    r++;
                }
            }
            else if(nums[i] == 1){
                if(i < w) i++;
                else if(i == w){
                    i++;
                    w++;
                }
                else{
                    int temp = nums[w];
                    nums[w] = nums[i];
                    nums[i] = temp;
                    w++;
                }
            }
            else{
                if(i >= w){
                    i++;
                }
                else{
                    int temp = nums[w];
                    nums[i] = nums[w];
                    nums[w] = temp;
                    w--;
                }
            }
        }
        return;
    }
}