/*
 @ May 30 2016 Monday
 @ by Xin Liu 
*/

/**Description of the problem**/
/* LeetCode 299. Bulls and Cows
* You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. 
* Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit 
* and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). 
* Your friend will use successive guesses and hints to eventually derive the secret number.

For example:
  Secret number:  "1807"
  Friend's guess: "7810"
  Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
  
* Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. 
* In the above example, your function should return "1A3B".

* Please note that both secret number and friend's guess may contain duplicate digits, 

* for example:
    Secret number:  "1123"
    Friend's guess: "0111"
    In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, and your function should return "1A1B".
You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.

*/

// we use int type vector(or bool type) called flag to store whether this index is already been considered.
// this is to say, if this index is bull or a cow, then flag = 1, 
// if flag == 1 of index i, we should not consider this index while caculate bull and cow.
// there are several conditions should be considered: index i is a bull match, when we find cow match, we find this position.
//               this postion is already has a cow match.

class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0;
        int cows = 0;
        int len = secret.length();
        vector<int> flag (len, 0);
        for(unsigned i = 0; i < secret.size(); i++)
        {
            
          size_t found = guess.find(secret.at(i));
          if(secret.at(i) == guess.at(i))
          {
              bull++;
              flag.at(i) = 1;
          }
          else 
          {
			  //while not a bull match, and there exist thie element in other position.
            while(found != string::npos) 
            {
				// in this position, we should check if this position exist a bull match, and if the flag of this position is 1.
                if( (flag.at(found) == 0) && (secret.at(found) != guess.at(found)) )
                {
                       cows++;
                       flag.at(found) = 1;
                       break;
                }
                else found = guess.find(secret.at(i), found+1);
            }
            
          }
        }
    
     // change the int type to string type.   
        stringstream stream;  
        stream<<bull; 
        stringstream stream2;
        stream2<<cows;
        string result;
        result = stream.str();
        result += "A";
        
        result += stream2.str();
        result += "B";
        return result;
    }
};