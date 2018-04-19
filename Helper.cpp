/**
 * This file consists of a bunch of helper functions
 * that are used throughout the program
 * @author Aman Nagpal
 * @version 1.0
 */

#include <iostream>
#include "Helper.h"

/**
 * This function initializes an empty array
 * We set the default value of a slot to -1
 * @param data the array to initailize
 * @param size the size of the array
 */
void initializeArray(int data[], int size){

    for(int i = 0; i< size; i++){
        data[i] = -1;
    }
}

/**
 * This function geets the slots from the main memory that has the samee baseReg as the param
 * @param baseReg -> the address of the requested slot
 * @memory -> this is our main memory
 */
MemorySlot* getSlot(int baseReg, Memory* memory){

    // loop through all the slots
    // otherwise no need to free it because it is already empt
    // check if their baseReg matches the baseReg provided to us
    for(int i =0; i < memory->getNumberSlots(); i++){
        MemorySlot* slot = memory->getSlot(i);
        if(slot->getBaseReg() == baseReg) {
            // register found
            return slot;
        }

    }

     return NULL;
}




/**
 * This function copies the data from MemorySlot to the MainMemory "Memory.h"
 * @param memorySlot the memorySlot whose data we would copy
 * @param memory our main physical memory
 * @return true if all goes well otherwise false
 */
 bool copyFromSlotToMemory(MemorySlot* slot, Memory* memory, int dataSize){

    try {
        int* data = slot->getData();
        int baseReg = slot->getBaseReg();
        if(memory->putData(data, dataSize, baseReg))
            return true;
        else
            throw;
    }
    catch(...){
        return false;


    }



}

/**
 * This function takes in an array of integers and prints then ouut
 * @param arr -> the array to print
 * @param size -> the size of the array
 */
 void printIntArray(int* arr, int size){
     for(int i = 0; i < size; i++){
         cout << arr[i] << endl;
     }
 }
