

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



vector<int> findMode (int modeArray[], int size);

vector<int> findMode (int modeArray[], int size)
{
    
    vector<int> finalMode;
    int freqcy = 0;
    
    sort(modeArray, modeArray + size);
    
    for (int testSort = 0; testSort < size; testSort++)
    {
    
    for(int loop=0; loop<size; loop++)  //loop to go through the array
    {
        int modeCounter = 0;
        int testNumber = modeArray [loop];
    
        for(int eqTest=0; eqTest<size; eqTest++) //Check to see if number is found elsewhere in array
        {
            if(testNumber == modeArray[eqTest])   //if it is...
                modeCounter++;  //...then add one to modeCounter
        }
        
        if (modeCounter > freqcy) freqcy = modeCounter;
    }

 //   cout << freqcy << endl;
    }
/****** END OF FIRST LOOP *********/
    
    for(int loop=0; loop<size; loop++)  //loop to go through the array
    {
        int testTest;
        int modeCounter = 0;
        int testNumber = modeArray [loop];
        
        for(int eqTest=0; eqTest<size; eqTest++) //Check to see if number is found elsewhere in array
        {
            if(testNumber == modeArray[eqTest])   //if it is...
                modeCounter++;  //...then add one to modeCounter
        }
        
        if (modeCounter == freqcy)
            
        {
            if (modeArray[loop] != testTest)
            
            {testTest = modeArray[loop];
                finalMode.push_back(testTest);}
        
        
        }
        
    }
    
/****** END OF SECOND LOOP *********/

    return finalMode;
}




int main() {
 
    
    const int arraySize = 5;
    int testArray [arraySize] = {0,0,0,0,0};
    
    findMode (testArray, arraySize);
    
    
    return 0;
}