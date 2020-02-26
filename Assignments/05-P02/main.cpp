///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Zachary Kingcade
// Email:            zachkingcade@gmail.com
// Label:            05-P02
// Title:            Assignment 5 - Processing in Linear Time
// Course:           CMPS 3013
// Semester:         Spring	2020
//
// Description:
//       program loads in a list and serches that list for substrings that are
//		 passed in by the user
//
//
// Files:            
//		JsonFacade.hpp
//		DictList.hpp
//		Timer.hpp
//		Termio.hpp
//		json.hpp
/////////////////////////////////////////////////////////////////////////////////

//----------PreCompiler Directives----------
#include "JsonFacade.hpp"
#include "DictList.hpp"
#include <algorithm>
#include "Timer.hpp"
#include <iostream>
#include "Termio.h"
#include <fstream>
#include <string>
#include <vector>

//----------Prototypes----------
std::string wordLookUp(DictList &,std::string);

//----------Main----------
int main (){
    int itemIndex;                //used to keep track of where the letters having
                                  //been searched for apear in the dictinary                            
    std::string searchBar = "";   //keeps track of string being searched for
	std::string resultsHolder;	  //holds the string returned by wordLookUp
	int jsonSize;				  //keeps track of the size of the json vectors
    Timer clock;				  //used to track how long loads and look ups take
    long loadms;				  //stores the time returned by clock in ms
	Term::IO stream;			  //used to print to the console and to clear 
								  //the console
	std::ofstream out;			  //used to store results in a output log file
	
	//open the log file to keep track of results
	out.open("log.txt");

	//Fully clear screen for print using a 200x100 wall of spaces starting
	//at the very top of the console
	//set up cleanScreen;
	std::string cleanScreen = "";
	for (int i = 0; i < 100; i++){
		cleanScreen += "                                                                                                    ";
		cleanScreen += "                                                                                                    ";
		cleanScreen += '\n';
	}
	//print
	stream << Term::Point(0,0);
	stream << cleanScreen << Term::Point(0,0);

	//----------Load Up Our Linked-List Dictionary-----------------------------
    //start our clock to estimate how long it takes to load up our ditionary 
	//into our linked list
    clock.Start();

    //---Set up Dictinary---
    JsonFacade book("dict_w_defs.json");//create dictinary object from json
	DictList dict;

	jsonSize = book.getSize();
	for (int i = 0; i < jsonSize; i++){
		dict.insert(book.getKey(i),book.getValue(book.getKey(i)));
	}

    //stop the timer on our clock and print the time to console
    clock.End();
    stream << "Time to load up linked-list|\tMilliseconds: " << std::to_string(clock.MilliSeconds());
	stream << "\tSeconds: " << std::to_string(clock.Seconds()) << '\n';
	//print to log
	clock.End();
    out << "Time to load up linked-list|\tMilliseconds: " << std::to_string(clock.MilliSeconds());
	out << "\tSeconds: " << std::to_string(clock.Seconds()) << '\n';

	//----------Word Lookup Loop----------
	//exit the loop when ~ is pressed
	while (searchBar != "~"){
		//read in our desired substring
		std::cin >> searchBar;

		//clear the lookup area
		stream << Term::Point(0,0);
		stream << cleanScreen << Term::Point(0,0);

		//print searchBar
		stream << "search: " << searchBar << '\n';

		//look up the term and track lookup time
		clock.Start();

		resultsHolder = wordLookUp(dict, searchBar);

		clock.End();
		//print time to find recommendations and the 10 recommended words
    	stream << "Time to lookup " << searchBar <<  ":\tMilliseconds: " << std::to_string(clock.MilliSeconds());
		stream << "\tSeconds: " << std::to_string(clock.Seconds()) << '\n';
		stream << resultsHolder << '\n';


		//print to log file
		out << "----------------------------------------------------------------------";
		out << "search: " << searchBar << '\n';
		out << "Time to lookup " << searchBar <<  ":\tMilliseconds: " << std::to_string(clock.MilliSeconds());
		out << "\tSeconds: " << std::to_string(clock.Seconds()) << '\n';
		out << resultsHolder << '\n';
	}

	//close log file
	out.close();
	
} //End of Main

//----------Functions----------
/**
     * Public : wordLookUp
     * 
     * Description:
     *      used to lookup and find words containg a passed in substring within
	 *  	a passed in DictList object
     * 
     * Params:
	 * 		DictList list		List to be searched
	 * 		std::string word	substring to be looked for in list
     * 
     * Returns:
     *      std::string : the first 10 items found in the list with the word
	 *		substring, if 10 are not found it will be the ones found plus ---
	 *		where the rest of the words would have been
     */
//used to lookup and find words containg a passed in substring within a passed
//in DictList object
std::string wordLookUp(DictList list, std::string word){
	int matchesFound = 0;       //used to makes sure we only find the first 10
	std::string result = "";    //stores the first 10 results in a string
    //start from the front of the list
    list.reset();
    //go until you find the first 10 words or reach the end of the list
    while(matchesFound < 10 && !list.atEnd()){
      int temp = list.getWord().find(word);
      if (temp != std::string::npos){
        result += list.getWord() + ' ';
        matchesFound++;
      }
      list.forward();
    }
  //if you reached the end of the list without finding 10 words add "---"
  //where that word would be
	if (matchesFound < 10){
		for (int i = 0; i < 10 - matchesFound; i++){
			result += "--- ";
		}
	}

    //return our result
    return result;
}