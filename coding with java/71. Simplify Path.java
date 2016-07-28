/*
 @ July 27 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode  71. Simplify Path
* 
    Given an absolute path for a file (Unix-style), simplify it.

    For example,
     path = "/home/", => "/home"
     path = "/a/./b/../../c/", => "/c"
   
   
   click to show corner cases.
    Corner Cases:
     Did you consider the case where path = "/../"?
     In this case, you should return "/".
     Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
     In this case, you should ignore redundant slashes and return "/home/foo".


*/
	 

/**

*/
public class Solution {
    public String simplifyPath(String path) {
        //use stack to store result
        //. will remove the former element.
        // .. remove all the former element.
        //at first, divided input string into string array divided by '/'.
        
        List<String> sPath = new ArrayList<String>();
        int i=0;
        while(i < path.length()){
            if(path.charAt(i) == '/') i++;
            else{
                int j= i+1;
                while(j < path.length()){
                    if(path.charAt(j) != '/') j++;
                    else break;
                }
                String str = path.substring(i,j);
                sPath.add(str);
                i = j;
            }
        }
       
        i=0;
        Stack<String> result = new Stack<String>();
        while(i < sPath.size()){
            String st = sPath.get(i);
            if(st.equals(".")) i++;
            else if(st.equals("..")){
                if(!result.empty()) result.pop();
                i++;
            }
            else{
                st = "/" + st;
                result.push(st);
                i++;
            }
        }
        String real = new String();
        real = "";
        if(result.empty()) return "/";
        else{
            while(!result.empty()){
                real = result.peek() + real;
                result.pop();
            }
            return real;
        }
    }
}