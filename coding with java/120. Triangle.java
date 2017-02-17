/*
@ Feb 17 2017
@ by Xin Liu
*/

/************Description of the problem************/
/* 120. Triangle
*
 Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

*/


public class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int path = 0;
        List<Integer> laststep = new ArrayList<Integer>();
       // System.out.println(triangle.get(0).size());
        for(int i=0; i < triangle.size(); i++){
            List<Integer> current = new ArrayList<Integer>();
            for(int j=0; j<triangle.get(i).size(); j++){
                if(i == 0){
                    current.add(triangle.get(i).get(j));
                }
                else{
                    
                    int one;
                    int two;
                    if(j >0 && j < triangle.get(i-1).size()){
                        //System.out.println("test 1");
                        one = laststep.get(j-1);
                        two = laststep.get(j);
                        if(one >= two) current.add(two + triangle.get(i).get(j));
                        else current.add(one+triangle.get(i).get(j));
                    }
                    else if(j ==0){
                        current.add(laststep.get(j) + triangle.get(i).get(j));
                    }
                    else{
                        current.add(laststep.get(j-1) + triangle.get(i).get(j));
                    }
                }
            }
            
            laststep = current;
        }
        int min = laststep.get(0);
        for(int m=0; m<laststep.size(); m++){
            if(min > laststep.get(m)) min = laststep.get(m);
        }
        return min;
    }
    
}