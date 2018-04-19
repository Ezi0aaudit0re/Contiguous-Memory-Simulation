/**
 * THis is the header file for header functions
 * @author = Aman Nagpal
 * @version = 1.1
 */

#ifndef HELPER_H
#define HELPER_H

#include <iostream>

using namespace std;

#include "MemorySlot.h"
#include "Memory.h"

void initializeArray(int[], int);
MemorySlot* getSlot(int, Memory*);
bool copyFromSlotToMemory(MemorySlot*, Memory*);





#endif
