/*
 @ Jun 28 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 88. Merge Sorted Array
* 
   Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

   Note:
    You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. 
	The number of elements initialized in nums1 and nums2 are m and n respectively.

*/
	 




	 

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // this if-else to check the relationship between m and nums1.size(), the given m may be bigger or smaller than nums1.size()
		if(m==0){
            nums1 = nums2;
            return;
        } 
        else if(n==0) return;
        else if(m < nums1.size()) nums1.erase(nums1.begin()+m, nums1.end());
        else if(m > nums1.size()) m = nums1.size();
        else if(n > nums2.size()) n = nums2.size();
        else if(n < nums2.size()) nums2.erase(nums2.begin()+n, nums2.end());
        int i=0;
        int j=0;
        while(i < m){
            while(j < n){
                if(nums1.at(i+j) <nums2.at(j)) 
                    {   
                        break;
                    }
                else {
                    
                    nums1.insert(nums1.begin()+i+j, nums2.at(j));
                    j++;
                }
            }
            
            i++;
        }
        
        if(nums1.size() < m+n) nums1.insert(nums1.end(), nums2.begin()+j, nums2.end());
        return;
    }
};