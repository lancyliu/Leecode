/*
 @ Jun 22 2016 Monday
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 204. Count Primes
* 
   Count the number of prime numbers less than a non-negative number, n.

    Use Sieve of Eratosthenes algorithm to find all prime numbers up to n. 

*/
	 


/*
  Flow the hint in the description. Make sure consider all optimum point.
*/

class Solution {
public:
    int countPrimes(int n) {
         vector<bool> flag (n+1,false);
        int result = 0;
        if( n <= 2) return 0;
        for(int i = 2; i*i < n; i ++)
        {
            if(flag.at(i) == false)
            {
                for(int j = i*i ; j < n; j+= i)
                {
                         
                        if(flag.at(j) == false)
						{
						   flag.at(j) = true;
						   result += 1;
						}
                }
            }
            else continue;
        }
        return n-2-result;
    }
};