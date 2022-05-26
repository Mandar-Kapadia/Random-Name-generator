/**********************************************************************
 *  readme.txt template                                                   
 *  Random Writer 
 **********************************************************************/

Name: Mandar Kapadia

Hours to complete assignment: 6 hours or so 
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
    In this assignment we used Markov model to get predect diffrent text patterns in a given text doc.
    in the text it can predect diffrent chars and then will make diffrent strings based on the order and 
    given char.




  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
    In this modle I used a hashmap of strings and a hashmap of char ints. 
    and In this I would simple add all values using subscript and then would just use that to predect diffrent the coming chars.
    and i would uses prob to get what letters would come after that which would factor into making my string. 




/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
    for (int i = 0; i < (L - order); i++) {
        retChar = kRand(retString.substr(i , order));
        retString.push_back(retChar);
    }
i used a for loop that would get the nearest predection of the word then would push that back into strings for my generate funtions.

    int kgramFreq = freq(kgram);
    int randNumber = rand() % kgramFreq; //NOLINT
    int totalProb = 0;
    for (auto itr = RandWriterMap[kgram].begin(); itr != RandWriterMap[kgram].end(); itr++ ) { //NOLINT
        totalProb += itr->second;
        if (randNumber <= totalProb) {
            return itr->first;
        }
    }
in this I would get a probs by getting a random value of between the probs then I would simple add put the frequences and I would 
use the added frequences to get when totalProb was greater then prob this take into account for probs and gets values based on probs.

testingArc(([](int argc){ return (argc != 3);}) , argc);

I used a lambda to check if argc was 3.


/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
I think I did complete the whole assignment even using a lambda



/**********************************************************************
 *  Does your implementation pass the unit tests?
 *  Indicate yes or no, and explain how you know that it does or does not.
 **********************************************************************/
 Yes my test passes unit test which checks if my freq work and and chekc for invalid inputs.



 /**********************************************************************
 *  Describe where you used exceptions. 
 *  Provide files and lines of the code.
 ***********************************************************************/
   1) if ((unsigned)order != kgram.length()) {
        throw std::invalid_argument(" kgram is not k length"); //NOLINT
    }

   2) if (tester == RandWriterMap.end()) {
        throw std::invalid_argument(" kgram is not in the hashmaps");
    }
   3) auto tester2 = RandWriterMap.at(kgram).find(c);
        if (tester2 == RandWriterMap.at(kgram).end()) {
        throw std::invalid_argument(" c is not in the hashmap");
    }
    4)    if (order > L) {
        throw std::invalid_argument(" l is not k length"); //NOLINT
    }
    auto tester = RandWriterMap.find(kgram);
   5) if (tester == RandWriterMap.end()) {
        throw std::invalid_argument(" kgram is not in the hashmap");
    }

    6)if (func(argc)) {
         std::runtime_error("need 3 arguments");
    }
    I used these to test inputs in diffrent funtions the first obne is used to check if the given kgram is the size of korder if
    not that its not a valid input. I next test if the given c is a valid input if not that invalid input. 
    After that I would check if the L is atleast order long else it would not work. Number 5 is to check if the kgram is in our input 
    if not that invalid input. Last one is in my main where i check if argc has a valid input if not run time error.






 /**********************************************************************
 *  Describe where you used lambda expression if any
 *  Provide files and lines of the code.
 ***********************************************************************/
testingArc(([](int argc){ return (argc != 3);}) , argc);

I used a lambda to check if argc was 3.

/**********************************************************************
 *  Did you implemented program for extra poits? If yes, describe your 
 *  If yes, describe your implementation.
 ***********************************************************************/
no

/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/
I got help from ravi patel and andy


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
I had problems with going throught the array but i did figure it.


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
