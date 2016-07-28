/*
 @ July 23 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  55. Jump Game 
* 
    Given an array of non-negative integers, you are initially positioned at the first index of the array.

    Each element in the array represents your maximum jump length at that position.

    Determine if you are able to reach the last index.

    For example:
     A = [2,3,1,1,4], return true.

     A = [3,2,1,0,4], return false.


*/
	 

/**
1. if all element in the input array is bigger than 0, then the result will be true no matter what.
2. only if some element equals 0, the result maybe false.
   Thus, scanning the array from tail, 
     if nums[i] bigger than 0, continue
     if equals 0, then if nums[i-1] bigger than 1, then we can skip index i, result still be true. 
	 Thus we scan from index i-1, check if we can skip index i or not.
*/

public class Solution {
    public boolean canJump(int[] nums) {
        //if(nums.length ==0) return false;
        if(nums.length == 1) return true;
        if(nums[0] == 0) return false;
        int i = nums.length -2;
        while(i >=0){
            if(nums[i] != 0) i--;
            else{
                //nums[i] == 0, thus item befor index i must havs step that can skip this 0 index.
                int j = i-1;
                boolean pass = false;
                while(j >=0){
                    if(nums[j] <= i-j) j--;
                    else {
                        //if nums[j] > i-j that is in index j we can to at least i-j+1 step which will skip index i.
                        pass = true;
                        break;
                    }
                }
                if(pass) i--;
                else return false;
            }
        }
        return true;
    }
}