/*
 @ Jun 19 2016 Monday
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 225. Implement Stack using Queues
* 
   Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Notes:
You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).

*/
	 


// use two queue to implement the stack. 
//while pop the element, we pop all the element in one queue to get the element that should be poped in stack.
class Stack {
    private:
    queue<int> MyQu; 
    queue<int> MyQu2;
public:
    // Push element x onto stack.
    void push(int x) {
        if(!MyQu.empty())
           MyQu.push(x);
        else MyQu2.push(x);
    }

    // Removes the element on top of the stack.
	  // in this function, we remove all the element to the other queue. As a result, one queue will be empty.
	  // thus in other function, we should at first check whether the queue is empty or not.
    void pop() {
       if(!MyQu.empty()){
	   unsigned l = MyQu.size();
            for(unsigned i = 0; l; i++){
                if(i == l - 1)
                {
                    MyQu.pop();
                    return;
                }
               int x = MyQu.front();
               MyQu2.push(x);
               MyQu.pop();
           }
        }
        else
        {
			unsigned l = MyQu2.size();
            for(unsigned i = 0; l; i++){
                if(i == l - 1)
                {
                    MyQu2.pop();
                    return;
                }
               int x = MyQu2.front();
               MyQu.push(x);
               MyQu2.pop();
           }
        }
    }

    // Get the top element.
	  // get the last element in the queue, this element is the newest element in the data structure, 
	  //which should be at the top of stack structure.
    int top() {
        if(!MyQu.empty()) return MyQu.back();
        else return MyQu2.back();   
    }

    // Return whether the stack is empty.
    bool empty() {
        if(MyQu.empty() && MyQu2.empty()) return true;
        else return false;
    }
};