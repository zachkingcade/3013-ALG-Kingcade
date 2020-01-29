///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Zachary Kingcade
// Email:            zachkingcade@gmail.com
// Label:            A02
// Title:            Commenting C++ Code
// Course:           CMPS 3013
// Semester:         Spring 2019-2020
//
// Description:
//       This assignment is more about breaking the ice with github, with a little 
//       to do with programming. Also to set a president when it come to commenting
//       programs in this class
//
/////////////////////////////////////////////////////////////////////////////////

//----------Precompiler Directives----------
#include <iostream>

using namespace std;

//----------Global Varibles----------
int A[100];     //unused int array of size 100

/**
 * Node
 * 
 * Description:
 *      A Storage wrapper for int varibles that holds pointers to other Nodes
 */
struct Node {
    int x;
    Node *next;
    Node() {
        x = -1;
        next = NULL;
    }
    Node(int n) {
        x = n;
        next = NULL;
    }
};

/**
 * List
 * 
 * Description:
 *      Storage class for int's with access to both front and back pushing 
 *      and popping
 * 
 * Public Methods:
 *      void        Push(int)
 *      void        Insert(int)
 *      void        PrintTail
 *      string      Print
 *      int         Pop()
 *      List        +operator
 *      int         []operator
 *      ostream     <<operator
 * 
 * Usage: 
 *      Used to store a list of int values
 *      
 */

class List {
private:
    Node *Head;     //points to the first item in the list
    Node *Tail;     //points to the last item in the list
    int Size;       //used to keep track of the number of item in the list

public:
    List() {
        Head = Tail = NULL;
        Size = 0;
    }

    /**
     * Public: Push
     * 
     * Description:
     *      IF the list is empty it initalizes the Head and Tail and adds an
     *      item to the list
     *      ELSE adds an item to the front of the list
     * 
     * Params:
     *      int     val     Value of the item to add to the list
     */
    void Push(int val) {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        if (!Head && !Tail) {
            Head = Tail = Temp;
        } else {
            Tail->next = Temp;
            Tail = Temp;
        }
        Size++;
    }

        /**
     * Public: Insert
     * 
     * Description:
     *      adds an item to the front of the list
     *      IF the Tail is not initalized, initalizes it
     * 
     * Params:
     *      int     val     Value of the item to add to the list
     */
    void Insert(int val) {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        // figure out where it goes in the list

        Temp->next = Head;
        Head = Temp;
        if (!Tail) {
            Tail = Head;
        }
        Size++;
    }
    /**
     * Public:  PrintTail
     * 
     * Description:
     *      Prints the value of the last item of the list
     */
    void PrintTail() {
        cout << Tail->x << endl;
    }

    /**
     * Public: Print
     * 
     * Description:
     *      returns a string of all the values of the list 
     *      seperated by ->'s
     * 
     * Returns:
     *      string of all the values of the list seperated
     *      by ->'s
     */
    string Print() {
        Node *Temp = Head;
        string list;

        while (Temp != NULL) {
            list += to_string(Temp->x) + "->";
            Temp = Temp->next;
        }

        return list;
    }

    /**
     * Public: pop
     * 
     * Description:
     *      removes and return an item from the list
     * 
     * Returns:
     *      return an item from the list
     */

    // not implemented
    int Pop() {
        Size--;
        return 0; //
    }

    /**
     * Public: + operator
     * 
     * Description:
     *      allows the adding of 2 lists together appending the second
     *      to the end of the first.
     * 
     * Params:
     *      List    List to be appended
     * 
     * Returns:
     *      A list containing the items of both lists
     */
    List operator+(const List &Rhs) {
        // Create a new list that will contain both when done
        List NewList;

        // Get a reference to beginning of local list
        Node *Temp = Head;

        // Loop through local list and Push values onto new list
        while (Temp != NULL) {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Get a reference to head of Rhs
        Temp = Rhs.Head;

        // Same as above, loop and push
        while (Temp != NULL) {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Return new concatenated version of lists
        return NewList;
    }

    /**
     * Public: Operator []
     * 
     * Description:
     *      Allows access to any item in the list as if it were
     *      an array
     * 
     * Params:
     *      int     index of what item in the list to access
     * 
     * Returns:
     *      int     value of the item in the list
     */
    int operator[](int index) {
        Node *Temp = Head;

        if (index >= Size) {
            cout << "Index out of bounds, exiting";
            exit(0);
        } else {

            for (int i = 0; i < index; i++) {
                Temp = Temp->next;
            }
            return Temp->x;
        }
    }

    /**
     * Public: Operator []
     * 
     * Description:
     *      Allows the printing of the entire list using
     *      the << operator
     * 
     * Params:
     *      List        List to be printed
     * 
     * Returns:
     *      ostream     out stream object allowing for the
     *                  use of multiple << operators in a row
     */
    friend ostream &operator<<(ostream &os, List L) {
        os << L.Print();
        return os;
    }
};

int main(int argc, char **argv) {
    List L1;
    List L2;

    for (int i = 0; i < 25; i++) {
        L1.Push(i);
    }

    for (int i = 50; i < 100; i++) {
        L2.Push(i);
    }

    //cout << L1 << endl;
    L1.PrintTail();
    L2.PrintTail();

    List L3 = L1 + L2;
    cout << L3 << endl;

    cout << L3[5] << endl;
    return 0;
}