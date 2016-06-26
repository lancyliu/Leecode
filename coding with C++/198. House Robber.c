/*
 @ Jun 24 2016 Monday
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 198. House Robber
* 
   You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
   the only constraint stopping you from robbing each of them is that adjacent houses have security system connected 
   and it will automatically contact the police if two adjacent houses were broken into on the same night.

   Given a list of non-negative integers representing the amount of money of each house, 
   determine the maximum amount of money you can rob tonight without alerting the police.

*/
	 


/*
Dynamic Programming.
Use hashMap to store the result.
*/
class Solution {
public:
    map<int, int> resultMap;
    
    int rob(vector<int>& nums) {
        
       
        if(nums.empty()) return 0;
		else if(nums.size() == 1) 
		{
			resultMap.insert(pair<int,int>(1, nums.at(0)) );
            return nums.at(0);
		}
        else if(nums.size() == 2)
        {
            //pick the maxmium one.
            if(nums.at(0) >= nums.at(1)) 
			{
				resultMap.insert(pair<int,int>(2, nums.at(0)));
                return nums.at(0);
			}
            else 
			{
				resultMap.insert(pair<int,int>(2, nums.at(1)));
				return nums.at(1);
			}
        }
        else
        {
			//if this result already been caculated, return the value stored in hashmap.
			map<int,int>::iterator it;
			if( !resultMap.empty()) 
			{
				it = resultMap.find((int)nums.size());
			    if(it != resultMap.end()) return resultMap[(int)nums.size()];
			}
             

            //in this condition. elements in nums >= 3.
            int result1, result2;
            int n1 = nums.at(0);
            int n2 = nums.at(1);
            int size = nums.size();
            nums.erase(nums.begin() + 0);
            nums.erase(nums.begin() + 0);
            
            int result = 0;
            if(n1 >= n2)
            {
                
                result = n1 + rob(nums);
                
                resultMap.insert(pair<int, int>(size, result));
                return result;
            }
            else
            {
               
               vector<int> nums1 = nums;
			

            //result1 represents if we choose the 1nd house. then we should pop the 2nd one(no adjacent)
              result1 = n1 + rob(nums1);
              
            
            //if we choose 2nd, then we should pop 3nd in nums.
              nums.erase(nums.begin() + 0);
			
              result2 = n2 + rob(nums);
            
			//result should be the bigger one between 1 & 2.
              if(result1 >= result2) result += result1;
              else result += result2;
              
            //store the result in hashmap.
              resultMap.insert(pair<int, int>(size, result));
              return result;
            }
        }
    }
};