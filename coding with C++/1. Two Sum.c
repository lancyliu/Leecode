/*
 @ July 7 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 1. Two Sum
* 
   Given an array of integers, return indices of the two numbers such that they add up to a specific target.

   You may assume that each input would have exactly one solution.

   Example:
    Given nums = [2, 7, 11, 15], target = 9,

    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1].
   UPDATE (2016/2/13):
    The return format had been changed to zero-based indices. Please read the above updated description carefully

*/
	 



/**
The rarget and elements in vector may be smaller than 0. 
in this problem in order to spend less time, I add two function.
This two function is to check if all the element in vector is smaller/bigger than 0. 
if false(means all smaller/bigger), we can delete all the element in tails that is bigger/smaller than target, 
and can skip the elements that is bigger/smaller than target while scanning.
However, if target >0, but elements in vector have <0, we can not skip element that is > target, cause this elements may be minus by elements smaller than 0.
*/
	 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
               
        if(nums.empty()) { 
            vector<int>result (2,0);
            return result;
        }
        //delete all the item that bigger than target.
        //cause we need to return the index of result, we just delete the element from tail.
        int flag1 = checkZero(nums);
        if(flag1 == false && target >=0){
           int m=nums.size()-1;
           while(m > 0){
            if((nums.at(m) <= target && target>=0) /*||(nums.at(m) >=target && target <= 0)*/) break;
            else {
                nums.erase(nums.begin()+m);
                m--;
            }
        }
        }
        
        int flag2 = checkZeroTwo(nums);
        if(flag2 == false && target <0){
          int m=nums.size()-1;
           while(m > 0){
            if((nums.at(m) >=target && target <= 0)) break;
            else {
                nums.erase(nums.begin()+m);
                m--;
            }
        }
        }
        
        //cout<<"nums"<<endl;
        int i=0;
        vector<int>result;
        
        while(i < nums.size()){
            int temp = nums.at(i);
            if((nums.at(i) > target && target >=0 && flag1==false) ||(nums.at(i) <target && target <= 0 && !flag2)) i++;
            else{
                for(int j=i+1; j<nums.size(); j++){
                    if(temp + nums.at(j) == target){
                        result.push_back(i);
                        result.push_back(j);
                        break;
                    }
                  }
                i++;
            }
        }
        return result;
    }
    
    bool checkZero(vector<int>num){
        //check whether num contains element smaller than 0.
        for(unsigned i=0; i<num.size(); ++i){
            if(num.at(i) <0) return true;
        }
        return false;
    }
    //check if num contain element that is bigger than 0;
    bool checkZeroTwo(vector<int>num){
        for(unsigned i=0; i<num.size(); ++i){
            if(num.at(i) >0) return true;
        }
        return false;
    }
};