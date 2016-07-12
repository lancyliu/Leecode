/*
 @ July 10 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 4. Median of Two Sorted Arrays
* 
    There are two sorted arrays nums1 and nums2 of size m and n respectively.

    Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

    Example 1:
     nums1 = [1, 3]
     nums2 = [2]

     The median is 2.0
    Example 2:
     nums1 = [1, 2]
     nums2 = [3, 4]

     The median is (2 + 3)/2 = 2.5

*/
	 



/**
There are following conditions:
1. nums1 empty, nums2 empty
2. nums1 empty, nums2 not 
3. nums1 not, nums2 empty
4. both not empty.
  4.1 all element in nums1 is smaller than it in nums2
  4.2 all element in nums2 is smaller than it in nums1
  4.3 others: merge these two vector, to get a new sorted array.
  
Note: how to compute median.
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size();
        
        int flag = 0;
        int index;
        if(size %2 ==0){
            flag = 2;
            index = size/2 -1;
        }
        else{
            index = size/2;
        }
        //if both vector is empty
        if(nums1.empty() && nums2.empty()) return 0;
        else if(nums1.empty() && !nums2.empty()){
            //if nums2 is empty but nums2 not
            if(flag ==2){
                double result = (double)(nums2.at(index) + nums2.at(index+1))/2;
                return result;
            }
            else return nums2.at(index);
        }
        else if(!nums1.empty() && nums2.empty()){
           // if nums1 not empty, nums2 empty
           //cout<<"checkpoin 1"<<endl;
            if(flag ==2){
                //cout<<"checkpoin 1"<<endl;
                //cout<<index<<endl;
                double result = (double)(nums1.at(index) + nums1.at(index+1))/2;
                return result;
            }
            else return nums1.at(index);
        }
        else{
            //if both vector is not empty
            //since vector is sorted. if the last element in nums1 is smaller than the first element in nums2, or in reverse.
              // in such condition, the array is sorted. there are several conditions.
            if(nums1.at(nums1.size()-1) <= nums2.at(0)){
                if((index <= nums1.size()-1) && flag==0) return nums1.at(index);
                else if(index < (nums1.size() -1) && flag==2){
                    double result = (double)(nums1.at(index) + nums1.at(index+1))/2;
                    return result;
                }
                else if(index == (nums1.size() -1) && flag==2){
                    double result = (double)(nums1.at(index) + nums2.at(0))/2;
                    return result;
                }
                else if(flag ==2){
                    double result = (double)(nums2.at(index - nums1.size()) + nums2.at(index - nums1.size()+1))/2;
                    return result;
                }
                else return nums2.at(index - nums1.size());
            }
            else if(nums2.at(nums2.size()-1) <= nums1.at(0)){
                if((index <= nums2.size()-1)  && flag==0) return nums2.at(index);
                else if(index < (nums2.size() -1) && flag==2){
                    double result = (double)(nums2.at(index) + nums2.at(index+1))/2;
                    return result;
                }
                else if(index == (nums2.size() -1) && flag==2){
                    double result = (double)(nums2.at(nums2.size()-1) + nums1.at(0))/2;
                    return result;
                }
                else if(flag ==2){
                    double result = (double)(nums1.at(index - nums2.size()) + nums1.at(index - nums2.size()+1))/2;
                    return result;
                }
                else return nums1.at(index - nums2.size());
            }
            else{
                //if both vector is not empty, and the order of this two array is not decides.
                //most complex condition.
                //merge this two list just to  index +1;
                vector<int> merge;
                int i=0;
                int j=0;
                while(i<nums1.size() && j<nums2.size()){
                    if(merge.size() >= index+2) break;
                    if(nums1.at(i) <= nums2.at(j)) {
                        merge.push_back(nums1.at(i));
                        i++;
                    }
                    else{
                        merge.push_back(nums2.at(j));
                        j++;
                    }
                }
                if(merge.size() >= index+2){
                    if(flag ==2){
                        double result;
                        result = (double)(merge.at(index) + merge.at(index+1))/2;
                        return result;
                    }
                    else return merge.at(index);
                }
                else{
                    while(i<nums1.size()){
                        if(merge.size() >= index+2) break;
                        merge.push_back(nums1.at(i));
                        i++;
                    }
                    while(j<nums2.size()){
                        if(merge.size() >= index+2) break;
                        merge.push_back(nums2.at(j));
                        j++;
                    }
                    if(flag ==2){
                        double result;
                        result = (double)(merge.at(index) + merge.at(index+1))/2;
                        return result;
                    }
                    else return merge.at(index);
                    
                }
            }
            return 0;
        }
    }
};