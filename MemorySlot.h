/*
 * This file is the header file of memroySlots
 * This class represents the methods and attribbutues that represent a slot in memory
 * @author Aman Nagpal
 * @version 1.0
 */

#ifndef MEMORYSLOT_H
#define MEMORYSLOT_H


#include <iostream>


using namespace std;

class MemorySlot{

    private:
        int baseRegister;
        int limitRegister;
        int blockEnd;
        bool allocated; // used to track if the partion has data in it
        int dataSize; // The size of the data
        int* data;
        string allocatedSlotName;

    public:
        bool fillDataInSlot(int[], int);
        bool getAllocated(); // check if the the slot is taken
        int getLimit(); // get the limit of thhe memory slot
        int getBaseReg();
        int* getData();
        int getValue(int); // return the value at that particular location
        int getDataSize();
        void setAllocated();
        void setAllocated(string);
        void printData();
        int getEndBlock();
        void setSlotName(string);
        void freeSlot();
        string getSlotName();
        MemorySlot(int, int);
        ~MemorySlot();
};


#endif
