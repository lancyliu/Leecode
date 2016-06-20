/*
 @ Jun 20 2016 Monday
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 217. Contains Duplicate
* 
   Given an array of integers, find if the array contains any duplicates. 
   Your function should return true if any value appears at least twice in the array, 
   and it should return false if every element is distinct.
*/
	 



//use hash map to solve this problem. hash key store the value in nums array. hash value store the frequency of key in array.
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.empty()) return false;
        map<int,int> numMap; // the key is the value in nums, the value match to the key is the times this element appeared in nums
        map<int, int>::iterator it;
        for(unsigned i = 0; i < nums.size(); i++)
        {
            it = numMap.find(nums.at(i));
            if( it != numMap.end())
            {
                //already exists the element.
                numMap.at(nums.at(i)) += 1;
                if(numMap.at(nums.at(i)) >= 2) return true;  // if it appeared more than twice, return true.
            }
            else
            {
                //this element do not exists. then add this element to the map.
                numMap.insert( pair<int,int>(nums.at(i), 1) );
            }
        }
        return false;
    }
};