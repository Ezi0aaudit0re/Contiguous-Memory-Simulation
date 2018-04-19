/**
 * This file consists of the implementation of methods
 * @author Aman Nagpal
 * @version 1.0
 */

#include <iostream>
#include "MemorySlot.h"
#include "Helper.h"

using namespace std;

/**
 * Constructor
 * @param baseReg -> base register where does the slot start
 * @param limtReg -> The size of the slot
 */

MemorySlot::MemorySlot(int baseReg, int limitReg){

    this->allocatedSlotName = "Not Allocated";
    this->baseRegister = baseReg;
    this->limitRegister = limitReg;
    this->blockEnd = this->baseRegister + this->limitRegister - 1;
    this->data = new int[this->getLimit()]; // set all the values to 0
    initializeArray(this->data, this->getLimit());
    this->allocated = false;
    this->dataSize = 0;
}



/**
 * This method puts data in the particular memory Slot
 * Note we put the data in the Memory class attribute data
 * @param data[] -> The data to puut in the memory slot
 */
bool MemorySlot::fillDataInSlot(int data[], int size){

    try{
        if(size <= this->limitRegister){
            // check size so doesnot go to another partition
            for (int i = 0; i < size; i++){
                this->data[i] = data[i];
            }
            this->dataSize = size;
            return true;
        }
        throw; // throw an excception otherwise
    }
    catch(...){
        cout << "Cannot initialize data in main memory" << endl;
        return false;
    }
}

/**
 * This is a deconstrctor that is called when the slot is freed i.e data is deleted inside the slot
 */
void MemorySlot::freeSlot(){
    initializeArray(this->data, this->getLimit()); // set all the values to 0
    this->allocated = false;
    this->dataSize = 0;
}


/**
 * Deconstrucutor for this method
 */
 MemorySlot::~MemorySlot(){
     // free the space allocated for data this is the only space allocated on the heap
     delete[] this->data;

 }

/**
 * This method prints a snapshot of the slot
 * BaseReg: <value>, Limit: <value>, End: <value>, Alloocated: <True/False>
 */

 void MemorySlot::printData(){
     cout << "Name: " << this->getSlotName() << " BaseReg: " << this->getBaseReg() << ", Limit: " << this->getLimit() << ", End: " << this->getEndBlock() << ", Allocated: " <<  this->getAllocated() << endl;
 }


/************************* GETTERS AND SETTERS ***********************/


/**
 * Getter for limitReg
 */
int MemorySlot::getLimit(){
    return this->limitRegister;

}

// base register getter
int MemorySlot::getBaseReg(){
    return this->baseRegister;

}


/**
 * Get the value in the data at that specific location
 */
int MemorySlot::getValue(int location){
    return this->data[location];
}

int MemorySlot::getEndBlock(){
    return this->blockEnd;

}

/**
 * Get the size of the data in the slot
 */
 int MemorySlot::getDataSize(){
    return this->dataSize;
 }

 /**
  * Get the name of the Slot
  */
  string MemorySlot::getSlotName(){
      return this->allocatedSlotName;
  }

 /**
  * Get the data in the slot
  */
  int* MemorySlot::getData(){
     return this->data;
  }


/**
 * We use a variable to check if the slot is allocated.
 * We could have looped through the data to check
 * if any value is different from default value but that would be O(n)
 *
 * with the concept i choose to use checking time becomes O(1)
 * @return true if the slot is filled
 */

 bool MemorySlot::getAllocated(){
     return this->allocated;

 }

 /**
  * Set allocated to true
  */
 void MemorySlot::setAllocated(){
      this->allocated = true;
 }

 /**
  * Override the Set allocated method
  * set setAllocated to trueu
  * set the name of the slot
  */
 void MemorySlot::setAllocated(string name){
      this->allocated = true;
      this->setSlotName(name);
 }



 /**
  * Set the name of the slot when allocated
  */
  void MemorySlot::setSlotName(string slotName){
      this->allocatedSlotName = slotName;

  }
