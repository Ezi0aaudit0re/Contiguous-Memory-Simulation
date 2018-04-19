/**
 * This is the header for the interface file
 * @author Aman Nagpal
 * @version 1.0
 */

#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include "Includes.h"
#include "MemorySlot.h"
#include "Memory.h"
#include "Helper.h"


Memory* mm_init(int); // initialize the memory
int my_malloc(int size, Memory*, string); // allocate a slot of a particular size limitReg
void my_free(int baseReg, Memory*); // free the memory slot from base register
void my_read(int baseReg, Memory*); // read the slot with base register given
void my_write(int base_reg, int data[], int size, Memory*); // write the data to that slot



#endif // MEMORY_SLOT
