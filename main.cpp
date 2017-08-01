/**********************************
 ** Program Filename: findMode.cpp
 ** Author: reuben youngblom
 ** Date: November 9th 2016
 ** Description: Much of the description is in inline comments, but essentially, I did this the way Prof. Alcon suggested.  Went through the array once and found the highest frequency for any value, and then went through again and pulled any value that appeared that many times and put it in a vector.  I explain a test (below) that I used to weed out any duplicates.
 ** Input: No real input, but the main will have an array and pass the array and size to findMode function
 ** Output: No real output, but it will return a vector
 **********************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> findMode (int modeArray[], int size);  //function prototype, creates a function that will return a vector of integer type.  It takes in an array and the size of the array.



 //main function, used for testing
 
 int main() {
    
    
    const int arraySize = 5;
    int testArray [arraySize] = {1,1, 1, 5, 6};
    
    findMode (testArray, arraySize);
    
    
    return 0;
}


vector<int> findMode (int modeArray[], int size)   //function definition
{
    
    vector<int> finalMode;   //this creates a vector called finalMode, that will be filled with the mode(s) and ultimately returned from the function
    int freqcy = 0;   //this initializes int freqcy to zero. This int will be used to keep track of how often a number pops up in the array
    
    sort(modeArray, modeArray + size);  //this will sort the array. I decided to do this first, so everything is in ascending order when I deal with it.
    
    /*****************
     I set this program up just like Dr. Alcon suggested.  First, I ran through a for loop. This first loop determines the most times any number appears in the array by iterating through the loop once for each number in the array, and while still "holding" that number in memory, running through the array again via a nested loop to check and see if any other numbers are the same.  If they are, it adds one to my count variable (modeCounter).
    ******************/
    
    /*********FIRST LOOP*************/
    
    for (int testSort = 0; testSort < size; testSort++)  //this is my first for loop.
    {
    
    for(int loop=0; loop<size; loop++)  //loop to go through the array
    {
        int modeCounter = 0; //initializes modeCounter to 0
        int testNumber = modeArray [loop]; //creates testNumber, and sets it equal to whatever number the first loop happens to be on (i.e. it depends where in the array it is).
    
        for(int eqTest=0; eqTest<size; eqTest++) //Loop to check to see if number is found elsewhere in array
        {
            if(testNumber == modeArray[eqTest])   //Does this by comparing the number from the outside loop to a full pass through the array.  If it is found elsewhere...
                modeCounter++;  //...then add one to modeCounter, which is my count variable
        }
        
        if (modeCounter > freqcy) freqcy = modeCounter; //once the second loop (nested loop) goes all the way through, this checks to see if the counter variable got higher than it has ever been before.  If yes (and so automatically on the first go-around), it replaces the old number with this new higher number.
    }
    }
/****** END OF FIRST LOOP *********/
 
  /**************************
    At this point in my code, the program has determined how often the mode(s) appear in the array, and the array is sorted. Now it moves on to the second loop, which will take the number(s) that is the mode(s) and pull them out, and put them in a vector.  It does three main things:  One, it determines which numbers are the mode numbers, by checking how often each number pops up against the "freqcy" varuable.  If it shows up as many times as the "freqcy" variable (which holds the number of times the modes show up), then it knows that that number is a mode.  Then it does the second thing: it checks to see if this number is already in the vector.  I did this via an if test.  Since they are already sorted, I created a variable testTest. The programs checks to see if testTest is equal to the number it's thinking about putting into the vector (because, at this point, any nmumber that's gotten this far has passed the "does it show up 'freqcy' number of times" test), and if it IS NOT equal, the program moves on to the third thing it does, which is execute the conditional statement.  This conditional sets testTest equal to the number it just put into the vector (and, since the array is sorted already, means that this filter will only catch duplicates—the first instance of any number will be set to testTest, and subsequent instances will fail the conditional test that checks to see if the current number is equal to testTest), AND then it pushes the number in question into the vector via a push_back statement.
    *****************************/
    
/*******SECOND LOOP************/
    
    for(int loop=0; loop<size; loop++)  //loop to go through the array
    {
        int testTest;  //used to hold last int pushed into vector, and weed out any that are duplicates
        int modeCounter = 0;  //same as above: keeps track of instances of a number
        int testNumber = modeArray [loop];  //sets testNumber equal to whatever number the program is on in the array.
        
        for(int eqTest=0; eqTest<size; eqTest++) //Same as in first loop. Checks to see if number is found elsewhere in array
        {
            if(testNumber == modeArray[eqTest])   //if it is (since testNumber won't change here, it'll stay on the number from the outside loop)...
                modeCounter++;  //...then add one to modeCounter (again)
        }
        
        if (modeCounter == freqcy)  // if the number appears as many times as the frequency of the mode, it's a mode
            
        {
            if (modeArray[loop] != testTest)  //test to see if it's already in the vector.  This checks the number being considered against variable testTest.  If it's the first instance of the number, they will not be equal and the conditional will execute.  But any subsequent times the number comes up (which will all be in the row since they're sorted) the conditional will not execute.
            
            {testTest = modeArray[loop];  //conditional sets testTest to current number, AND
                finalMode.push_back(testTest);}  //adds the number to the vector.
            for (vector<int>::const_iterator i = finalMode.begin(); i != finalMode.end(); ++i)
               cout << *i << ' ';
        }
    }
    
/****** END OF SECOND LOOP *********/

    return finalMode;  //returns vector finalMode
}