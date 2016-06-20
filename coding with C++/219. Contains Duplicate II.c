/*
 @ Jun 19 2016 Monday
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 219. Contains Duplicate II
* 
Given an array of integers and an integer k, 
find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] 
and the difference between i and j is at most k.

*/
	 


//there are several ways implemented. however the first method costs too much time.
// use hash map structure, if this element already exists, compare the index of this two element. if < k return true.
// if > k, update the hash table, continue.
// if hash table do not contain this element, insert it to the hash table.
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      
        //case 1: if k = 0;
        if(k == 0 || nums.empty()) return false;
        /***
        //case 2: if k is larger than the size of vector, then we just find whether there are two same element in vector.
        if(k >= (int)nums.size())
        {
            for(unsigned i = 0; i < nums.size() -1; i ++)
            {
                for(unsigned j = i+1; j < nums.size(); j++)
                {
                    if(nums.at(i) == nums.at(j)) return true;
                }
            }
        }
        else 
        {  
            for(unsigned i = 0; i < nums.size(); i ++)
           {
               for(int j = 1; j <= k; j++)
              {
                  if(i + j >= (int)nums.size()) break;
                  if(nums.at(i) == nums.at(i + j)) return true;
              }
           }
        }
        return false;
        ***/
        map<int,int> numMap;
        map<int,int>::iterator it;
        for(unsigned i = 0; i< nums.size(); i++)
        {
            it = numMap.find(nums.at(i));
            //if this element already exist. check if the index if smaller than k.
            if(it != numMap.end())
            {
                if(i == numMap.at(nums.at(i)) ) continue;
                else if(i - numMap.at(nums.at(i)) <= k) return true;
                else numMap[nums.at(i)] = i;
            }// if this element is not exist. insert it into the map.
            else
            {
                numMap.insert(pair<int, int>(nums.at(i), i));
            }
        }
        return false;
    }
};