///////////////////////////////////////////////////////////////////////////////
//
// Author:           Zach Kingcade
// Email:            zachkingcade@gmail.com
// Label:            P01
// Title:            Program 01 - Array Based Stack
// Course:           3013
// Semester:         Spring 2020
//
// Description:
//       Completing of a class implementing an array based stack
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

/**
 * ArrayStack
 * 
 * Description:
 *      Array based stack
 * 
 * Public Methods:
 *      ArrayStack()        Default constructor
 *      ArrayStack(int s)   Constructor starts the stack at a size of s
 *      bool Empty()        Checks weather the stack is empty or not
 *      bool Full()         Checks weather the stack is full or not
 *      Peek()              Returns the top of the stack without deleting it
 *      int Pop()           Returns and deletes the top item of the stack
 *      void print()        prints the entire array to the console
 *      bool push(int x)         adds an item to the stack and returns if it was added succefully or not
 *      void ContainerGrow()       resizes the array based on the current size of the array
 * 
 * Usage: 
 *      - See main program
 *      
 */
class ArrayStack{
private:
  int *A;           // pointer to array of int's
  int size;         // current max stack size
  int top;          // top of stack 

public:
 /**
  * ArrayStack
  * 
  * Description:
  *      Constructor no params
  * 
  * Params:
  *     - None
  * 
  * Returns:
  *     - NULL
  */
  ArrayStack(){
    size = 10;
    A = new int[size];
    top = -1;
  }

 /**
  * ArrayStack
  * 
  * Description:
  *      Constructor size param
  * 
  * Params:
  *     - int size
  * 
  * Returns:
  *     - NULL
  */
  ArrayStack(int s){
    size = s;
    A = new int[s];
    top = -1;
  }

 /**
  * Public bool: Empty
  * 
  * Description:
  *      Stack empty?
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      [bool] true = empty
  */
  bool Empty(){
    return (top <= -1);
  }
  
 /**
  * Public bool: Full
  * 
  * Description:
  *      Stack full?
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      [bool] true = full
  */
  bool Full(){
    return (top >= size-1);
  }

 /**
  * Public int: Peek
  * 
  * Description:
  *      Returns top value without altering the stack
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      [int] top value if any
  */
  int Peek(){
    if(!Empty()){
      return A[top];
    }
    
    return -99; // some sentinel value
                // not a good solution
  }

 /**
  * Public int: Pop
  * 
  * Description:
  *      Returns top value and removes it from stack
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      [int] top value if any
  */
  int Pop(){
    if(!Empty()){
      if (top < size /2){
          ContainerShrink();
      }  
      return A[top--];
    }

    return -99; // some sentinel value
                // not a good solution
  }

 /**
  * Public void: Print
  * 
  * Description:
  *      Prints stack to standard out
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      NULL
  */
  void Print(){
    for(int i=0;i<=top;i++){
      cout<<A[i]<<" ";
    }
    cout<<endl;
  } 

 /**
  * Public bool: Push
  * 
  * Description:
  *      Adds an item to top of stack
  * 
  * Params:
  *      [int] : item to be added
  * 
  * Returns:
  *      [bool] ; success = true
  */
  bool Push(int x){
    if(Full()){
      ContainerGrow();
    }
    if(!Full()){
      A[++top] = x;
      return true;
    }
    
    return false;
    
  }

 /**
  * Public void: ContainerGrow
  * 
  * Description:
  *      Resizes the container for the stack by doubling
  *      its capacity
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      NULL
  */
  void ContainerGrow(){
    int newSize = size*2;       // double size of original
    int *B = new int[newSize];  // allocate new memory

    for(int i=0;i<size;i++){    // copy values to new array
      B[i] = A[i];
    }

    delete [] A;                // delete old array

    size = newSize;             // save new size

    A = B;                      // reset array pointer

  }

   /**
  * Public void: ContainerShrink
  * 
  * Description:
  *      Resizes the container for the stack by cutting
  *      its capacity in half
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      NULL
  */

  void ContainerShrink(){
    int newSize = size *.5;      // double size of original
    int *B = new int[newSize];   // allocate new memory

    for(int i=0;i<newSize;i++){ // copy values to new array
      B[i] = A[i];
    }
    
    delete [] A;                // delete old array

    size = newSize;             // save new size

    A = B;                      // reset array pointer
  }

 /**
  * Public int: checkSize
  * 
  * Description:
  *      return the current number of spots in memory allocated for the stack
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      current number of spots in memory allocated for the stack
  */
  int checkSize(){
      return size;
  }

 /**
  * Public int: checktop
  * 
  * Description:
  *      return the current index of top
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      current index of top
  */
  int checkTop(){
      return top;
  }

};

// MAIN DRIVER
// Simple Array Based Stack Usage:
int main() {
  ArrayStack stack;
  int r = 0;

  for(int i=0;i<30;i++){
    r = rand() % 100;
    r = i+1;
    cout << stack.checkSize() << ":" << stack.checkTop() <<":\t";
    stack.Print();
    if(!stack.Push(r)){
      cout<<"Push failed"<<endl;
    }
  }

  for(int i=0;i<25;i++){
    cout << stack.checkSize() << ":" << stack.checkTop() <<":\t";
    stack.Print();
    stack.Pop();
  }
}