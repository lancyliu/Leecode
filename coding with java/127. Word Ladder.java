/*
@ Feb 17 2017
@ by Xin Liu
*/

/************Description of the problem************/
/* 127. Word Ladder
*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
UPDATE (2017/1/20):
The wordList parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.
*/


public class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        
        Set<String> current = new HashSet<String>();
        Set<String> past = new HashSet<String>();
        Set<String> words = new HashSet<String>(wordList);
        Set<String> endPoint = new HashSet<String>();
        if(!words.contains(endWord)) return 0;
        endPoint.add(endWord);
        current.add(beginWord);
        if(beginWord.equals(endWord)) return 1;
        int length = 1;
        while(!current.isEmpty() && !endPoint.isEmpty() ){
            Set<String> temp = new HashSet<String>();
            //for(int j=0; j<current.size(); j++){
            if(current.size() > endPoint.size()){
                Set<String> mid = current;
                current = endPoint;
                endPoint = mid;
            }
            //past.addAll(current);
            for(String c : current){
                int i=0;
                for(String w: words){
                  if(diff(c , w)){
                    //only one difference. if current list contains this word means that we already cosider this word.
                    if(endPoint.contains(w)){
                        length++;
                        return length;
                    }
                    if(!past.contains(w)) {
                        temp.add(w);
                        past.add(w);
                    }
                }   
                }
            }
            
            //words.removeAll(temp);
             System.out.println(temp);
             System.out.println(endPoint);
            //System.out.println(words);
            current = temp;
            length++;
        }
        return 0;
    }
    
    boolean diff(String s1, String s2){
        if(s1.length() != s2.length()) return false;
        else{
            int l = 0;
            for(int i=0; i<s1.length(); i++){
                    if(s1.charAt(i) != s2.charAt(i)) l++;
                    if(l >1) return false;
            }
            if(l == 1) return true;
            else return false;
        }
    }
}