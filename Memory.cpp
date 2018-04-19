/**
 * This file represents the attributes and methods that represent the memory
 * @author Aman Nagpal
 * @version 1.0
 */

#include <iostream>
#include "Memory.h" // this also includes MemorySlot.h
#include "Includes.h"


using namespace std;


/**
 * Constructor that creates a memory of given size and initializes it
 * with valueus 0
 *
 */
Memory::Memory(int size){

    this->size = size;
    this->data = new int[this->size];
    this->numberSlots = 0;

    // create slots of randown limit
    int baseReg = 0;
    int limitReg = 0;
    cout << "Initializing Memory" << endl;
    do{
        cout << "Creating Slot" << endl;
        limitReg = MIN_NUM + ( std::rand() % ( MAX_NUM - MIN_NUM + 1 ) );
        MemorySlot* slot = new MemorySlot(baseReg, limitReg);
        slot->printData();
        this->slots.push_back(slot);
        this->numberSlots++;
        baseReg = baseReg + limitReg;
    }while((baseReg + limitReg) <= size);

}

/**
 * Deconstructor free up occuupied space on heap
 */
Memory::~Memory(){

    // delete the meory stack
    delete[] this->data;

    // delete all the values in the slots array
    for(int i = 0; i <(int)this->slots.size(); i++){
        delete this->slots.at(i); // this calls the deconstructor of MemorySlot class
    }

}

/**
 * Getter for number slots
 */
int Memory::getNumberSlots(){
    return this->numberSlots;

}

/**
 * Get slot at a particlar location
 */
MemorySlot* Memory::getSlot(int location){
    return this->slots.at(location);
}


/**
 * Get the vector containing information about all the slots
 */
 vector<MemorySlot*> Memory::getSlots(){
     return this->slots;

 }


 /**
  *  This method puts data into the memory starting from the reg provided
  * @param data[]
  * @param size  size of the data
  * @param baseReg -> The starting addrress where to put
  */
  bool Memory::putData(int* data, int dataSize, int baseReg){
      // loop through the data and copy into memory
      try{
          for(int i =0; i < dataSize; i++){
              if( this->putDataAtLocation((baseReg + i), data[i]) == false){
                  throw;
              };
          }
          return true;
      }
      catch(...){
          cout << "Therre was some problem when copying data from memory slot to memory" << endl;
          return false;

      }



  }

  /**
   * Put data in memory (meory->data) at a particlar location
   * @param location where to put data
   * @param data to puut in that location
   */
   bool Memory::putDataAtLocation(int loc, int data){
       try{
           this->data[loc] = data;
           return true;
       }
       catch(...){
           cout << "problem when entirng data at location" << loc << " data: " << data;
       }
       return false;

   }


  /**
   * This method prints a snapshot of the memory
   * BaseReg:  <value>, LimitReg: <value>, End: <value>, allocated: <value>, data: array
   */
   void Memory::printData(){
       for(int i = 0; i < this->getNumberSlots(); i++){
           MemorySlot* slot = this->getSlot(i);
           cout << "--------------------------------" << endl;
           cout << "Slot: " << slot->getSlotName() << endl;
           slot->printData();
           // print the data from memory
           this->getDataInSlot(slot->getBaseReg(), slot->getLimit());

           cout << "--------------------------------" << endl;

       }



   }



   /**
    * Loop through the memory from Basereg to baseReg + limitReg
    * @param BaseReg -> The starting point
    * @param LimitReg -> The limit of the slot
    */
    void Memory::getDataInSlot(int baseReg, int limitReg){
        // baseReg + limitReg act as the len and we go to -1
        for(int i = baseReg; i < (baseReg + limitReg); i++){
            if(this->getDataAtLocation(i) != 0)
                cout << this->getDataAtLocation(i) << endl;
        }

    }


    /**
     * This method returns data at a particular location
     * @parram location
     */
     int Memory::getDataAtLocation(int location){
         return this->data[location];

     }
