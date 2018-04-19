/**
 * This file contains the algortihm for best fit and first fit
 * @author Aman Nagpal
 * @version 1.0
 */

 #include <iostream>

 #include "Algorithm.h"

 using namespace std;


 /**
  * THis function allocates memory based on the best slot that is available
  * @param size -> the size of the memory needed
  * @param slots -> the vector of slots in memory
  * @return the base register of the allocated MemorySlot
            -1 if no slot found
  */

 int BestFit(int size, vector<MemorySlot*> slots, string name){
     // set the min to be 0 as all the slots will be atleast 1 address space
     int min = 0;

     // set the limit of the first as min
     MemorySlot* minSlot = NULL;

     // find the find the slot which is available
     // also finds the minum slot
     for(int i = 0; i < slots.size(); i++){
         int slotLimit = slots.at(i)->getLimit();
         if((slots.at(i)->getAllocated() == false) && (slotLimit >= size)){
             if(min == 0){
                min = slotLimit;
                minSlot = slots.at(i);
             }
             else if(slotLimit < min){
                min = slotLimit;
                minSlot = slots.at(i);
             }
             else{
                 continue;
             }
         }

     }


     if(minSlot != NULL){
        minSlot->setAllocated(name);
        return minSlot->getBaseReg();
     }
     else{
        cout << "No slot found to fit" << endl;
        return -1; // returns -1 of minSlot is still NULL i.e No slot satisfies the condition
     }

}




 /**
  * THis function allocates memory based on the first slot that is available
  * @param size -> the size of the memory needed
  * @param slots -> the vector of slots in memory
  * @return the base register of the allocated MemorySlot
            -1 if no slot found
  */

 int FirstFit(int size, vector<MemorySlot*> slots, string name){

     // loop through all the slots
     for(int i = 0; i < slots.size(); i++){
         // return the first empty slot with big enough size
         if(slots.at(i)->getLimit() >= size && (slots.at(i)->getAllocated() == false)){
             slots.at(i)->setAllocated();
             slots.at(i)->setSlotName(name);
             return slots.at(i)->getBaseReg();
         }


     }
     cout << "SLot of size " << size << " cannot be allocated using FIRST FIT because no slot of this size" << endl;
     return -1;



 }
