//----------PreCompiler Directives----------
#include "JsonFacade.hpp"
#include <algorithm>
#include "Timer.hpp"
#include "Termio.h"
#include <string>
#include <vector>

//----------Prototypes----------
void printOver(Term::IO,Term::Point, int, int);

//----------Main----------
int main (){
    int itemIndex;                          //used to keep track of where the letters having been searched for
                                            //apear in the dictinary
    string key;                             
    string searchBar = "";                  //keeps track of string being searched for
    Term::IO stream;                        //controls our in and out to and from the console
    Term::Point reset(0,0);

    //---Set up Dictinary---
    JsonFacade book("dict_w_defs.json");    //create dictinary object from json file
    vector<string> keys = book.getKeys();
    sort(keys.begin(),keys.end());

    //---Word Lookup Loop---
    printOver(stream,reset,30,200);

    while(true){
        //get new character and add to search bar
        char tempkey;
        stream >> tempkey;
        if(tempkey != 8 && tempkey != 127){
            searchBar += tempkey;
        }
        else{
            searchBar = searchBar.substr(0, searchBar.length() - 1);
        }

        //clear the old output
        printOver(stream,reset,11,130);
        stream << searchBar << "\n";

        itemIndex = std::lower_bound(keys.begin(), keys.end(), searchBar) - keys.begin();
        for (int i = 0; i < 10; i++){
            string tempKey = "&40" + keys[itemIndex + i];

            string tempValue = "&50" + book.getValue(keys[itemIndex + i]);
            std::replace(tempValue.begin(), tempValue.end(), '\n', '\t');
            tempValue.resize(100); 

            stream << tempKey << "\t\t" << tempValue << "\n";
        }


    }

}


//----------Functions----------

void printOver(Term::IO io,Term::Point start, int blockRow, int blockCol){
    io << start;
    for (int i = 0; i < blockRow; i++){
        for (int j = 0; j < blockCol; j++){
            io << " ";
        }
        io << "\n";
    }
    io << start;
}