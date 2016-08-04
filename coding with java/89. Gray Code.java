/*
 @ Aug 2 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  89. Gray Code
* 
    The gray code is a binary numeral system where two successive values differ in only one bit.

    Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. 
	A gray code sequence must begin with 0.

    For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

    00 - 0
    01 - 1
    11 - 3
    10 - 2
    Note:
     For a given n, a gray code sequence is not uniquely defined.

     For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

     For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.


*/
	 

/**
if n=2 :  00,  01,     11, 10
if n=3 :  000，001，011，010   110， 111，101，100 （add 0 befor former result, add 1 before reverse of former result.）
*/
public class Solution {
    public List<Integer> grayCode(int n) {
        List<Integer> l = new ArrayList<Integer>();
        
        if(n==0){
            l.add(0);
            return l;
        }
        List<List<Integer>>result = new ArrayList<List<Integer>>();
        int i=1;
        while(i <=n){
            if(result.isEmpty()){
                List<Integer> one = new ArrayList<Integer>();
                one.add(0);
                result.add(one);
                List<Integer> two = new ArrayList<Integer>();
                two.add(1);
                result.add(two);
            }
            else{
                List<List<Integer>> newresult = new ArrayList<List<Integer>>();
                for(int j=0; j< result.size(); ++j){
                    List<Integer> one = new ArrayList<Integer>();
                    one.add(0);
                    for(int m=0; m<result.get(j).size(); m++) one.add(result.get(j).get(m));
                    newresult.add(new ArrayList<Integer>(one));
                }
                for(int j=result.size()-1; j>=0; --j){
                    List<Integer> one = new ArrayList<Integer>();
                    one.add(1);
                    for(int m=0; m<result.get(j).size(); m++) one.add(result.get(j).get(m));
                    newresult.add(new ArrayList<Integer>(one));
                }
                result = newresult;
            }
            i++;
        }
        System.out.println(result.get(0).get(0));
        System.out.println("size" + result.size());
        
        for(int x=0; x<result.size(); x++){
            int number = 0;
            for(int y=0; y<result.get(x).size(); y++){
                number += result.get(x).get(y) * Math.pow(2, result.get(x).size()-1-y);
            }
            l.add(number);
        }
        return l;
    }
}