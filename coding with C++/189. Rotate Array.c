/*
 @ Jun 24 2016 Monday
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 190. Reverse Bits
* 
   Rotate an array of n elements to the right by k steps.

   For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

   Note:
    Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

*/
	 


/*

*/
class Solution {
public:
 void rotate(vector<int>& nums, int k) {
        if(k == 0) return;
        else if(k >= nums.size())
        {
			while(k >= nums.size()) k = k - (int)nums.size();
           // cout<<k;
            rotate(nums, k);
			return;
        }
		else
		{
		// for now, k is smaller than nums.size().
        //use a vector to store the elements should be removed.
        vector<int> extra;
        k = nums.size() - k;
        for(unsigned i = 0; i < k; i ++)
        {
            int temp = nums.at(0);
            extra.push_back(temp);
            nums.erase(nums.begin());
        }
        
        for(unsigned j = 0; j < extra.size(); j++)
        {
            int temp = extra.at(j);
            nums.push_back(temp);
        }
		return;
		}
        
    }
};