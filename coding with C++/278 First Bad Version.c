/*
 @ May 30 2016 Monday
 @ by Xin Liu 
*/

/**Description of the problem**/
/* LeetCode 278. First Bad Version
* You are a product manager and currently leading a team to develop a new product. 
* Unfortunately, the latest version of your product fails the quality check. 
* Since each version is developed based on the previous version, all the versions after a bad version are also bad.

* Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

* You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. 
* You should minimize the number of calls to the API.

*/


/*

*/
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int version =n /2;
        int upperlevel = n;
        int lowerlevel = 0;
        while((version != 0) && (version != n) && (upperlevel - lowerlevel != 1)){
            if(isBadVersion(version))
            {
                //isBadVersion return true, means that version is bad, then search 0---version
                //else search version---n
                upperlevel = version;
                version = (upperlevel-lowerlevel) /2;
            }
            else{
                //check version -- n
                lowerlevel = version;
                version = (upperlevel - lowerlevel) /2 + lowerlevel;
            }
            
        }
		//after binary search, the first bad version is between upperlevel and  lowerlevel.
        if(isBadVersion(lowerlevel)) return lowerlevel;
        else return upperlevel;
    }
};