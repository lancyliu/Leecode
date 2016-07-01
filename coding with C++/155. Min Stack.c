/*
 @ Jun 27 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 155. Min Stack
* 
   Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

   push(x) -- Push element x onto stack.
   pop() -- Removes the element on top of the stack.
   top() -- Get the top element.
   getMin() -- Retrieve the minimum element in the stack.
   Example:
     MinStack minStack = new MinStack();
     minStack.push(-2);
     minStack.push(0);
     minStack.push(-3);
     minStack.getMin();   --> Returns -3.
     minStack.pop();
     minStack.top();      --> Returns 0.
     minStack.getMin();   --> Returns -2.

*/
	 


/*
maintain the minimum element while pushing and poping.
*/
class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> currentMin;
    int numElement;
    vector<int> mystack;
    MinStack() {
        numElement = 0;
    }
    
    void push(int x) {
        mystack.push_back(x);
        numElement ++;
        if(numElement >=2){
           if(x < currentMin.at(numElement-2)) currentMin.push_back(x);
           else currentMin.push_back(currentMin.at(numElement -2)); 
        }
        else currentMin.push_back(x);
        
        return;
    }
    
    void pop() {
       if(!mystack.empty()) {
           mystack.pop_back();
           numElement --;
           currentMin.pop_back();
       }
        return;
    }
    
    int top() {
        if(!mystack.empty()) return mystack.at(numElement-1);
        else return 0;
    }
    
    int getMin() {
       if(!currentMin.empty()) return currentMin.at(numElement-1);
       return 0;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */