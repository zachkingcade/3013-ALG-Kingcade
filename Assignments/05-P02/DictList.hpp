/**
 * DictList
 * 
 * Description:
 *      Link List for storing dictionary definitions
 * 
 * Public Methods:
 *      void insert(std::string word, std::string definition)
 *      void sortedInsert(std::string word, std::string definition)
 *      void remove()
 *      bool atEnd()
 *      void forward()
 *      void backward()
 *      void reset()
 *      void setWord(std::string word)
 *      std::string getWord()
 *      void setDefinition(std::string definition)
 *      std::string getDefinition()
 * 
 * 
 * Private Methods/classes:
 *      struct Node()
 * 
 * Usage: 
 *      DictList myDict;
 *      myDict.insert("DictList","Is an awesome program but kinda slow")
 *      cout << myDict.getWord() << '\t';
 *      cout << myDict.getDefinition();
 *      myDict.remove();
 * 
 *      terminal:
 *      DictList    Is an awesome program but kinda slow
 *      
 */

//------------PreCompiler Directives----------
#include<string>


class DictList {
    //node for storing our data and linking our points
    struct Node {
        std::string word;
        std::string definition;
        Node *next;
        Node *previous;

        Node(std::string word = "", std::string definition = ""){
        this->word = word;
        this->definition = definition;
        next = nullptr;
        previous = nullptr;
        }
    };

public://------------------------------
    /**
     * Public : insert
     * 
     * Description:
     *      inserts a word and its definition into the list
     * 
     * Params:
     *      std::string word        word to be added
     *      std::string definition  definition to be added
     * 
     */
    void insert(std::string word, std::string definition){
        //create our node to link and add
        Node *tempNode = new Node(word,definition);
        //if the list is empty
        if (head == nullptr){
            head = tempNode;
            tracker = tempNode;
        //if we're not at the end of the list
        } else if (tracker->next != nullptr){
            Node *nextNode = tracker->next;
            tracker->next = tempNode;
            tempNode->previous = tracker;
            nextNode->previous = tempNode;
			tempNode->next = nextNode; 
        //if we are at the end of the list
        } else {
            tracker->next = tempNode;
            tempNode->previous = tracker;
			tracker = tracker->next;
        }
    }

    /**
     * Public : sortedInsert
     * 
     * Description:
     *      inserts a word and its definition into the list sorted
     *      via character, assumes a sorted list
     * 
     * Params:
     *      std::string word        word to be added
     *      std::string definition  definition to be added
     * 
     */
	void sortedInsert(std::string word, std::string definition){
		//if the list is empty
        if (head == nullptr){
            insert(word,definition);
		}
		//find where to insert item first
		//start at the front
		tracker = head;
		//use a flag so our while logic dosen't get out of hand
		bool spotFound = false;
		//while a spot as not been found and we are not at the end
		//of the list
		while (spotFound == false && tracker->next != nullptr){
			if (word > tracker->word && word < tracker->next->word){
				spotFound = true;
			} else {
				tracker = tracker->next;
			}
		}
		insert(word,definition);
	}

    /**
     * Public : remove
     * 
     * Description:
     *      inserts a word and its definition into the list sorted
     *      via character, assumes a sorted list
     * 
     */
    void remove(){
        //if the tracker is not at the front of the list
        if (tracker->previous != nullptr){
            //use temporary node to swap link previous and next of the nodes
            //infront of and behind one being deleted
            Node *tempPrevious = tracker->previous;
            tempPrevious->next = tracker->next;
            tempPrevious->next->previous = tempPrevious;
            //deletes the object being pointed to
            delete tracker;
            //put tracker at the node before the one being deleted
            tracker = tempPrevious;
        } else {
			head = tracker->next;
			head->previous = nullptr;
			delete tracker;
			tracker = head;
		}

    }

    /**
     * Public : atEnd
     * 
     * Description:
     *      tells if the list tracker is at the end of the list
     */
    bool atEnd(){
        if(tracker->next != nullptr){
            return false;
        }else {
            return true;
        }
    }

    /**
     * Public : forward
     * 
     * Description:
     *      moves the list tracker forward by one item
     */
    void forward(){
        if (tracker->next != nullptr){tracker = tracker->next;}
    }

        /**
     * Public : backward
     * 
     * Description:
     *      moves the list tracker backward by one item
     */
    void backward(){
        if (tracker->previous != nullptr){tracker = tracker->previous;}
    }

    /**
     * Public : reset
     * 
     * Description:
     *      sets the tracker back to the head of the list
     */
	void reset(){
		tracker = head;
	}

    /**
     * Public : setWord
     * 
     * Description:
     *      Describe the functions purpose
     * 
     * Params:
     *      std::string word    word to change
     */
    void setWord(std::string word){tracker->word = word;}

    /**
     * Public : getWord
     * 
     * Description:
     *      returns the word tracker is point to
     * 
     * Returns:
     *      returns the word tracker is point to
     */
    std::string getWord(){return tracker->word;}

    /**
     * Public : setDefinition
     * 
     * Description:
     *      sets the definition of the word the tracker is pointing to
     * 
     * Params:
     *      value to change definition to
     */
    void setDefinition(std::string definition){tracker->definition = definition;}

    /**
     * Public : getDefinition
     * 
     * Description:
     *      returns the definition of the word the tracker is pointing to
     * 
     * Returns:
     *      returns the definition of the word the tracker is pointing to
     */
    std::string getDefinition(){return tracker->definition;}


private://------------------------------
    Node *head = nullptr;
    Node *tracker = nullptr;

};