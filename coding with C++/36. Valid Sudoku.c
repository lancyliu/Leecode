/*
 @ July 9 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 36. Valid Sudoku
* 
    Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

    The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


    A partially filled sudoku which is valid.

    Note:
      A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

*/
	 



/**
There are three rules of sudoku:
1.Each row must have the numbers 1-9 occuring just once.
2.Each column must have the numbers 1-9 occuring just once.
3.And the numbers 1-9 must occur just once in each of the 9 sub-boxes of the grid.

we use three loops to check rule 1&2.
for rule three, we store the input board into a new vector<vector> each inner vector is a sub-boxes. then we can check the sub-boxes.
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int i=0;
        int j=0;
        //check rows and cols
		//check rule 1&2
        while(i<board.size()){
            vector<char> c = board.at(i);
            j=0;
            while(j < c.size()){
                char ch = c.at(j);
                if(ch == '.') j++;
                 else {
                   for(int m=j+1; m<c.size(); m++){
                       if(c.at(m) == ch) return false;
                    }
                   for(int n=i+1; n<board.size(); n++){
                       char temp = board.at(n).at(j);
                       if(temp == ch) return false;
                       }
                        j++;
                }
               
            }
            i++;
        }
        //check rule 3.
        //check every block
        int m=0;
        
        vector<vector<char>> blocks;
        while(m < board.size()){
            int n=0;
            while(n<board.at(m).size()){
                char cc = board.at(m).at(n);
                //cout<<"cc"<<cc<<"  ";
                    int x = n/3;
                    int y = m/3;
                    int index = 3*y +x;
                    //cout<<index<<endl;
                    if(index >=blocks.size()){
                        vector<char> ve;
                        ve.push_back(cc);
                        blocks.push_back(ve);
                    }
                    else blocks.at(index).push_back(cc);
                    n++;
               
            }
            //cout<<"check poing 1"<<endl;
            m++;
        }
        
        m=0;
       
        while(m<blocks.size()){
            int n=0;
            while(n <blocks.at(m).size()){
                char ccc = blocks.at(m).at(n);
                if(ccc == '.') n++;
                else {
                   //cout<<ccc<<endl;
                   for(int w=n+1; w<blocks.at(m).size(); ++w){
                       if(ccc == blocks.at(m).at(w)) return false;
                   }
                   n++;
                }
            }
            m++;
        }
        return true;
    }
};