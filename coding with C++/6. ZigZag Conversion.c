/*
 @ July 7 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 6. ZigZag Conversion
* 
   The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

   P   A   H   N
   A P L S I I G
   Y   I   R
   And then read line by line: "PAHNAPLSIIGYIR"
   Write the code that will take a string and make this conversion given a number of rows:

   string convert(string text, int nRows);
   convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

*/
	 



/**
store zigzag type string in a string type vector.
according the numRows and index of string s, caculate the position the element belong to.
*/
	 
class Solution {
public:
    string convert(string s, int numRows) {
        if(s.empty()) return s;
        if(numRows <=1) return s;
        vector<string> result;
        //int inner = numRows -2;
        int i=0;
        while(i<s.size()){
			
            //according to the display pattern, in cols zigzag type have two sizes, one is longer and one is shorter we consider this two size as a group.
			//each group's size = 2*numRows-2， then according to the index i we can infer the position the element belong to in the group.
			//each rows stored as a string, all string stored in vector. 
			//the same position in each group should be stored in same rows which means in same string.
			int resi = (i)%(2*numRows-2);
            if(resi >=numRows) resi = 2*numRows - resi -2;
            if(resi >= result.size()){
                string temp;
                temp.push_back(s.at(i));
                result.push_back(temp);
            }
            else{
                result.at(resi).push_back(s.at(i));
            }
            i++;
        }
        //cout<<"test sign1"<<endl;
		//convert the vector into a string.
        string r;
        int j=0;
        while(j<result.size()){
            r.append(result.at(j));
            j++;
        }
        return r;
    }
};