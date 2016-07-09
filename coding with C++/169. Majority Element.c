/*
 @ Jun 25 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 169. Majority Element
* 
    Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

    You may assume that the array is non-empty and the majority element always exist in the array. 

*/
	 


/*
use hash map to store (elements in nums)(number of times appeared in nums). once the times is bigger than n/2, return the element.
*/
class Solution {
public:
int majorityElement(vector<int>& nums) {
        if(nums.empty()) return 0;
        map<int,int> numMap;
        map<int,int>::iterator it;
        int n = nums.size();
        for(unsigned i = 0; i< nums.size(); i++){
            //it = numMap.find(nums.at(i));
			if(numMap.empty()) numMap.insert(pair<int,int>(nums.at(i),1));
			else
			{  
				for(it = numMap.begin(); it != numMap.end(); ++it)
                {
                    if(it -> first == nums.at(i)){
                       it -> second += 1;
                        if(it -> second > n/2) return it->first;
                    }
                }
				numMap.insert(pair<int,int>(nums.at(i),1));
			}
        }
        return nums.at(n-1);
    }
};