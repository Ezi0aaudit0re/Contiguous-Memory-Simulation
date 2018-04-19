/**
 * This file is the main driver of the project
 * @athor Aman Nagpal
 * @version 1.0
 */

#include <iostream>

using namespace std;

#include "Includes.h"
#include "Interface.h"
#include "Memory.h"

/**
 * This is the entring point of the program
 */
int main(){

    // initialize the memory
    Memory* memory = new Memory(MEMORY_SIZE);

    // allocate the memory
    cout << "Allocating Slots" << endl;
    int addr1 = my_malloc(10, memory, "addr1 10");
    int addr2 = my_malloc(12, memory, "addr2 12");
    int addr3 = my_malloc(9, memory, "addr3 9");
    int addr4 = my_malloc(8, memory, "addr4 8");
    int addr5 = my_malloc(14, memory, "addr5 14");
    cout << "Slots Allocated" << endl;

    // check which slots got allocated
    memory->printData();


    // write to the allocated memory
    // if addr1 all the values will be 1
    // if addr2 all the valueus will be 2
    // int data1[] = {1, 1, 1, 1, 1};
    // my_write(addr1, data1, 4, memory); // len 4 goes in slot 1
    // int data2[] = {2, 2, 2, 2, 2, 2, 2,2,2 ,2}; // len 10 go in slot: 2
    // my_write(addr2, data2, 10, memory );
    // int data3[] = {3, 3, 3,3,3,3,3,3,3,3}; // len 10 go in slot: 3
    // my_write(addr2, data3, 10, memory );
    // int data4[] = {4,4,4,4,4,4,4,4,4,4,4,4};// len 12 shold go in slot: 4
    // my_write(addr2, data4, 12, memory );
    // int data5[] = {5, 5, 5, 5, 5, 5, 5,5 ,5 ,5, 5, 5, 5};// len 13 shold go in slot: 5
    // my_write(addr2, data5, 13, memory );


    //memory->printData(); // a pictuure of what allocated memory looks like























}
