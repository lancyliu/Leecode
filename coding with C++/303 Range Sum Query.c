/*
 @ May 30 2016 Monday
 @ by Xin Liu 
*/

/**Description of the problem**/
/* LeetCode 303. Range Sum Query - Immutable
* Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

* Example:
* Given nums = [-2, 0, 3, -5, 2, -1]

* sumRange(0, 2) -> 1
* sumRange(2, 5) -> -1
* sumRange(0, 5) -> -3
* Note:
* You may assume that the array does not change.
* There are many calls to sumRange function.

*/


/*
create a vector numArray, which store the sum from 0 --i
in the first loop, caculate the value of numArray
according to i, j we get the result by: numArray.at(j) - numArray.at(i -1)
*/
class NumArray {
    public:
        vector<int> numArray;
public:
    NumArray(vector<int> &nums) {
        for(unsigned i = 0; i < nums.size(); i++)
        {
           if(i == 0) numArray.push_back( nums.at(i));
           else
           {
               numArray.push_back( nums.at(i) + numArray.at(i-1) );
           }
        }
    }

    int sumRange(int i, int j) {
    if(i > j) return 0;
    else if( i == 0) return numArray.at(j);
	else 
	{   
		return numArray.at(j) - numArray.at(i - 1);
	}
    }
};