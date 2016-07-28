/*
 @ July 23 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  60. Permutation Sequence
* 
    The set [1,2,3,…,n] contains a total of n! unique permutations.

    By listing and labeling all of the permutations in order,
     We get the following sequence (ie, for n = 3):

     "123"
     "132"
     "213"
     "231"
     "312"
     "321"
   Given n and k, return the kth permutation sequence.

   Note: Given n will be between 1 and 9 inclusive.


*/
	 

/**
Method1: according to k, caculate the result. That is :
     There are n! kinds of result,  k/(n-1)! is the number the on the first digit of result.
Method2: caculate all the permutation , then found the kth elements(too slow.)
*/

public class Solution {
    public String getPermutation(int n, int k) {
        
        List<Integer> result = new ArrayList<Integer>();
        List<Integer> map = new ArrayList<Integer>();
        
       // List<Integer> plus = new ArrayList<Integer>();
        //caculate (n-1)*(n-2)....
        int nn = 1;
        int i=1;
        while(i <n){
            nn = nn * (n-i);
            map.add(i);
            i++;
        }
        map.add(n);
        
        int first = k/nn;
        int resi = k%nn;
        if(resi == 0 && first != 0) first -= 1;
        result.add(map.get(first));
        map.remove(first);
        i=1;
        k = k-(first)*(nn);
        
        while(nn != 1){
            //find the next number should be added to the result
           // System.out.println(result.get(result.size()-1));
            nn = nn/(n-i);
            int index = k/nn;
            resi = k%nn;
            
            if(resi ==0 && index !=0) {
                index -= 1;
                k = k-(index)*(nn);
            }
            else k = resi;
            
           //if(nn == 1) index -= 1;
            result.add(map.get(index));
            map.remove(index);
            i++;
        }
        
        if(result.size() < n){
            for(int m=0; m<map.size(); m++)
               result.add(map.get(m));
        }
        
        String str = new String();
        str = "";
        for(int j=0; j<result.size(); j++){
            str += result.get(j);
        }
        
        return str;
        /**
        List<Integer> result = new ArrayList<Integer>();
        List<List<Integer>> allre = new ArrayList<List<Integer>>();
        
        permutation(n,k,result,1, allre);
        
        List<Integer> r = allre.get(k-1);
        String str = new String();
        str = "";
        for(int i=0; i<r.size(); i++){
            str += r.get(i);
        }
        
        return str;
        */
    }
/**    
    private void permutation(int n, int k, List<Integer> result, int index, List<List<Integer>> allre){
        if(index > k && result.size() == n) return;
        
        if(result.size() == n) {
            allre.add(new ArrayList<Integer>(result));
            index = index+1;
        }
        //System.out.println(index);
        for(int i=1; i<= n; i++){
            if(result.contains(i)) continue;
            else{
                result.add(i);
                permutation(n, k, result, index, allre);
                result.remove(result.size() -1);
            }
        }
    }
*/
}