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
#include <fstream>

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
      if (top < size /2 && size / 2 > 10){
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
  //---Veribles---
  ArrayStack stack(10);   //Structure used to store and process our data with a starting size of 10
  int item;               //used to store the read in number we are processing
  int max = 10;            //Keeps track of the largest the stack has gotten
  int changes = 0;        //Tracks the amount of times the size of the stack has changed
  int previousSize = 10;  //Keeps track of the size the stack was the last time something was added or subtracted;
  ifstream inFile;        //In file stream which we us to reasd in our data

  //open our data file
  inFile.open("nums_test.dat");

  while(inFile >> item){
    if (item % 2 == 0){
      //if item is even
      stack.Push(item);
      //if this is the largest the stack has been store current size
      if(stack.checkSize() > previousSize){max = previousSize;}
    } else {
      //if item is odd
      stack.Pop();
    }
    //check if the size of the stack has changed due to a push or pop
    if (previousSize != stack.checkSize()){
      changes++;
      previousSize = stack.checkSize();
    }
  }

  //print our results
  cout << "######################################################################\n\n";
  cout << "   Assignment 4 - Resizing the Stack\n";
  cout << "   CMPS 3013\n";
  cout << "   Zachary Kingcade\n\n";
  cout << "   Max Stack Size:\t" << max << '\n';
  cout << "   End Stack Size:\t" << stack.checkSize() << '\n';
  cout << "   Stack Resized:\t" << changes << " times\n\n";
  cout << "######################################################################\n";
}