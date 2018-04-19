/**
 * This is a header file of memory
 * this file represents what a memory looks like in our project
 * @author Aman Nagpal
 * @version 1.0
 */
#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>


using namespace std;

#include <vector>
#include "MemorySlot.h"

class Memory{

    private:
        int numberSlots;
        int* data; // array of addressable slots size with values of type int
        int size; // total number of addresable slots
        //int* freeSlots;
        //int* occupiedSlots;
        vector<MemorySlot*> slots; // consists of all the partitions in the memory

    public:
        Memory(int);
        ~Memory();
        int getNumberSlots();
        vector<MemorySlot*> getSlots();
        MemorySlot* getSlot(int);
        bool putData(int*, int, int);
        void printData();
        void getDataInSlot(int, int);
        bool putDataAtLocation(int, int);
        int getDataAtLocation(int);
};

#endif // INCLUDES_H
