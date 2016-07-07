/*
 @ July 1 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 67. Add Binary
* 
   Given two binary strings, return their sum (also a binary string).

   For example,
    a = "11"
    b = "1"
    Return "100".

*/
	 



/**
Method 1: turen the binary string a into a int 10 number, then add this two number, then turn the number into binary string type.
   However, this method are limited since int type have a limit in c++
Method 2: iterativly process two string, construct the result according the rule of adding two binary number.
*/
	 
class Solution {
public:
    string addBinary(string a, string b) {
        
        int i = a.size();
        int j = b.size();
        int dif = a.size() - b.size();
      
        int temp = 0;
        string result;
        while(i >0){
            //if size of a == size of b, then difference will be 0
            // if a > b, all string b is scanned, some element in a not scanned. at end i!= 0
            // or if b > a. at the end i==0. 
            if(i<= dif) break;
            else if(a.at(i-1) == b.at(j-1)){
				//if a.at() == b.at() ==0, the reuslt will be 0, and no flip.
				// if ==1, the reuslt will be 0, but have a flip.
                if(temp ==0) result.push_back('0');
                else result.push_back('1');  
                if(a.at(i-1) == '0') temp = 0;
                else temp = 1;
            }
            else{
               //if only one of these is 1, the reult will be 1, no flip.
                if(temp == 0) {
                   result.push_back('1');
                    temp = 0;
                }
                else{
                    result.push_back('0');
                    temp = 1;
                } 
            }
            i--;
           
            j--;
        }
        //if a is longer than b.
        if(a.size() - b.size() >0){
            int g = a.size() - b.size();
            //if no flip from former, just push the element in a into the result,.
			if(temp ==0) {
                while(g >0){
                    result.push_back(a.at(g-1));
                    g--;
                }
            }
            else{
                //if have flip in former caculation. we should add 1, and check the conditon in a.
                while(g > 0){
                    if(a.at(g-1) =='0'){
                        result.push_back('1');
                        while(g >1) {
                            result.push_back(a.at(g-2));
                            g--;}
                        temp = 0;
                        break;
                    }
                    else{
                        result.push_back('0');
                        temp = 1;
                        g--;
                    }
                }
            }
        }
        //if b is longer than a, the condition is same with a.
        if(dif < 0){
            
            int g = b.size() - a.size();
            if(temp ==0){
                while(g>0){
                    result.push_back(b.at(g-1));
                    g--;
                }
            } 
            else{
                
                
                while(g > 0){
                    if(b.at(g-1) =='0'){
                        result.push_back('1');
                        while(g>1) {
                            result.push_back(b.at(g-2)); 
                            g--;}
                        temp = 0;
                        
                        break;
                    }
                    else{
                        
                        result.push_back('0');
                        temp = 1;
                        g--;
                    }
                }
            }
        }
        if(temp ==1) result.push_back('1');
        
        string r;
        // the result should be reverse to get the number .
        for(unsigned m=0; m<result.size(); m++){
            r.push_back(result.at(result.size()-1-m));
        }
       
        return r;
        
        
    }
    
    
    /****
    long long int to_int(string a){
        //convert a binary to int.
        long long int result = 0;
        for(unsigned i=0; i<a.size(); i++){
            char temp = a.at(i);
            int t = (int)temp - 48;
            result += t*pow(2,a.size()-1-i);
        }
        cout<<result<<endl;
        return result;
    }
    
    string to_binary(long long int x){
        //convert int x to a  binary representation string
        string result;
        if(x==0) result.push_back('0');
        while( x != 0){
            long long int resi = x%2;
            x = x/2;
            char temp = char(resi) +48;
            result.push_back(temp);
        }
        //cout<<result<<endl;
        string r;
        for(unsigned i=0; i<result.size(); i++){
            r.push_back(result.at(result.size()-1-i));
        }
        //cout<<r<<endl;
        return r;
    }
    ***/
};