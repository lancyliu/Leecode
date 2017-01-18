/*
@ Jan 17 2017
@ by Xin Liu
*/

/************Description of the problem************/
/* LeetCode 93. Restore IP Addresses
*
   Given a string containing only digits, restore it by returning all possible valid IP address combinations.

   For example:
   Given "25525511135",

   return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
* 
*/
/*use backtracking. however, knowledge about IP address protocol is neccessary
reference: http://www.cnblogs.com/higerzhang/p/4117279.html*/
public class Solution {
    public List<String> restoreIpAddresses(String s) {
        int length = s.length();
			List<String> result = new ArrayList<String>();
			if(length<4 || length >12) return result;
			else{
			    String temp = new String();
				dfs(result, s, temp, 0);
				return result;
			}
    }
    
    public void dfs(List<String> result, String s, String temp, int count){
			if(count==3 && isTrue(s)){
				result.add(temp+s);
				return;
			}

			else{
				for(int i=1; i< Math.min(4, s.length());i++){
					String str = s.substring(0,i);
					if(isTrue(str)){
						dfs(result,s.substring(i), temp+str+".",count+1);
					}
				}
			}
		}

	public	boolean isTrue(String str){
			if(str.charAt(0) == '0') return str.equals("0");
			int number = Integer.parseInt(str);
			return number<=255 && number>0;
		}
}