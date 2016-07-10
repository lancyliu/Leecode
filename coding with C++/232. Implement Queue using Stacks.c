/*
 @ July 9 2016 
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 232. Implement Queue using Stacks
* 
    Implement the following operations of a queue using stacks.

    push(x) -- Push element x to the back of queue.
    pop() -- Removes the element from in front of queue.
    peek() -- Get the front element.
    empty() -- Return whether the queue is empty.
   Notes:
    You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
    Depending on your language, stack may not be supported natively. 
	You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
    You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).

*/
	 



/**
modify the push function. in queue the element comes eailer is in the front of the queue, element comes later is in the back.
however, in stack, elements came earlier in the back, and will be pop earlier.
in push function, use two stack pop all the elements in one stack and add the new element to the empty stack, then push all other elements back.
*/

class Queue {
public:
   stack<int> s1;
   stack<int> s2;
    // Push element x to the back of queue.
    void push(int x) {
      if(s1.empty() && s2.empty()) s1.push(x);
      else{
          while(!s1.empty()){
              s2.push(s1.top());
              s1.pop();
          }
          s2.push(x);
          while(!s2.empty()){
              s1.push(s2.top());
              s2.pop();
          }
      } 
      return;
    }

    // Removes the element from in front of queue.
    void pop(void) {
        s1.pop();
        return;
    }

    // Get the front element.
    int peek(void) {
        int r = s1.top();
        return r;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        if(s1.empty() && s2.empty()) return true;
        else return false;
    }
};