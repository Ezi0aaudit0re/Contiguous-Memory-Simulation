/**
 * This file consists the BEST FIT and the FIRST FIT algorithm for allocating memory
 * @author Aman Nagpal
 * @version 1.0
 */



#include <iostream>

using namespace std;

#include "Memory.h"
#include "MemorySlot.h"

int BestFit(int, vector<MemorySlot*>, string);
int FirstFit(int, vector<MemorySlot*>, string);
