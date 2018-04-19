/**
 * This file is the interface for the program
 * Driver file calls methods from this file
 * @author Aman Nagpal
 * @version 1.0
 */

#include <iostream>
#include "Interface.h"
#include "Algorithm.h"
#include "Helper.h"



using namespace std;




/**
 * Initialize the memory with the given size
 * @param size -> The size of the memory
 */
Memory* mm_int(int size){

    Memory* memory = new Memory(size);
    return memory;

}


/**
 * Allocate the memory and return the base address
 * Allocates based on best fit or first fit whatever is set in #define
 * @param size -> The size of the memory we want to allocate
 * @return the baseReg address of the new slot
 */
int my_malloc(int size, Memory* memory, string name){

    int baseReg = -1;
    if(ALGO == 0){
        // BestFit
        baseReg = BestFit(size, memory->getSlots(), name);

    }
    else if (ALGO == 1){
        //First Fit
        baseReg = FirstFit(size, memory->getSlots(), name);

    }


    return baseReg;


}





/**
 * Free the slot whose starting address is given
 * @param -> baseReg the starting value of the slot
 */
void my_free(int baseReg, Memory* memory){

    MemorySlot* slot = getSlot(baseReg, memory);
    if(slot == NULL || (slot->getAllocated() == false)){
        // slot not found
        cout << "Address: " << baseReg << "is not the base Register for any slot or its not allocated" << endl;
    }
    else{
        // clear the slot by calling its deconstructor
        slot->freeSlot();
    }

}


/**
 * This function reads from the slot and copies it in the array upto the size
 * @param baseReg -> The starting address of the slot
 * @param data[] -> the array to read it to
 * @param size -> The length upto what to read
 */
void my_read(int baseReg, int data[], int size, Memory* memory){

    // get the slot which we are reading from
    MemorySlot* slot = getSlot(baseReg, memory);
    if(slot == NULL || (slot->getAllocated() == false)){
        cout << "Address" << baseReg << " is not available in the memory or its not allocated" << endl;
    }
    else{
        // check if we have valid size so that we donot go over to next slot
        if(size <= slot->getLimit()){
            // copy into data
            for(int i = 0; i < size; i++){
                data[i] = slot->getValue(i);
            }

        }

    }
}


/**
 * This method writes to the given slot
 * @param baseReg -> The starting address of the slot
 * @param data[] -> The data to write to the slot
 * @param size -> The amount of bites to write
 */
void my_write(int baseReg, int data[], int size, Memory* memory){

    MemorySlot* slot = getSlot(baseReg, memory);
    if(slot == NULL){
        cout << "Adress: " << baseReg << " is not available in the memory" << endl;

    }
    else{
        if(size <= slot->getLimit())
            slot->fillDataInSlot(data, size);
            // write to meory
            if(copyFromSlotToMemory(slot, memory) == false){
                cout << "Problem occured in my_write in interface at Base Register: " << baseReg << endl;

            }
    }
}
