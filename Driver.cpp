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
    cout << "\n\nAllocating Slots" << endl;
    int addr1 = my_malloc(ADDR_1_SIZE, memory, "addr1 10");
    int addr2 = my_malloc(ADDR_2_SIZE, memory, "addr2 12");
    int addr3 = my_malloc(ADDR_3_SIZE, memory, "addr3 9");
    int addr4 = my_malloc(ADDR_4_SIZE, memory, "addr4 8");
    int addr5 = my_malloc(ADDR_5_SIZE, memory, "addr5 14");
    cout << "Slots Allocated" << endl;

    // check which slots got allocated
    // memory->printData();


    // write to the allocated memory
    // if addr1 all the values will be 1
    // if addr2 all the valueus will be 2
    cout << "\n\n------ Adding Data -------" << endl;
    int data1[] = {1, 1, 1, 1, 1};
    my_write(addr1, data1, DATA_1_SIZE, memory); // len 4 goes in slot 1
    int data2[] = {2, 2, 2, 2, 2, 2, 2,2,2 ,2}; // len 10 go in slot: 2
    my_write(addr2, data2, DATA_2_SIZE, memory );
    int data3[] = {3, 3, 3,3,3,3,3,3,3,3}; // len 10 go in slot: 3
    my_write(addr3, data3, DATA_3_SIZE, memory );
    int data4[] = {4,4,4,4,4,4,4,4,4,4,4,4};// len 12 shold go in slot: 4
    my_write(addr4, data4, DATA_4_SIZE, memory );
    int data5[] = {5, 5, 5, 5, 5, 5, 5,5 ,5 ,5, 5, 5, 5};// len 13 shold go in slot: 5
    my_write(addr5, data5, DATA_5_SIZE, memory );



    // memory->printData(); // a pictuure of what allocated memory looks like


    cout << "\n\n------ Read data from the slots -------" << endl;
    // we read data from each addr - addr1, addr2 ... addr5 as these represent slots
    cout << "Data in slot 1" << endl;
    int readData1[DATA_1_SIZE];
    my_read(addr1, readData1, ADDR_1_SIZE, memory);
    printIntArray(readData1, DATA_1_SIZE);


    cout << "Data in Slot 2" << endl;
    int readData2[DATA_2_SIZE];
    my_read(addr2, readData2, DATA_2_SIZE, memory);
    printIntArray(readData2, DATA_2_SIZE);

    cout << "Data in Slot 3" << endl;
    int readData3[DATA_3_SIZE];
    my_read(addr3, readData3, DATA_3_SIZE, memory);
    printIntArray(readData3, DATA_3_SIZE);

    cout << "Data in Slot 4" << endl;
    int readData4[DATA_4_SIZE];
    my_read(addr4, readData4, DATA_4_SIZE, memory);
    printIntArray(readData4, DATA_4_SIZE);

    cout << "Data in Slot 5" << endl;
    int readData5[DATA_5_SIZE];
    my_read(addr5, readData5, DATA_5_SIZE, memory);
    printIntArray(readData5, DATA_5_SIZE);


    cout << "\n\n ----- Deleting Data from few slots ----------" << endl;
    // Free slot 1
    my_free(addr1, memory);
    // // Free slot 2
    my_free(addr2, memory);
    // // Free slot 3
    my_free(addr3, memory);


    // memory->printData(); // a pictuure of what allocated memory looks like

    cout << "\n\n ------- Allocation Again ---------- " << endl;

    int addr6 = my_malloc(ADDR_6_SIZE, memory, "addr6 19");
    int addr7 = my_malloc(ADDR_7_SIZE, memory, "addr7 13");


    memory->printData(); // a pictuure of what allocated memory looks like

    // add data to these new allocated slots
    int data6[] = {6, 6, 6, 6, 6, 6, 6,6 ,6 ,6, 6, 6, 6, 6};// len 13
    my_write(addr6, data6, DATA_6_SIZE, memory );
    int data7[] = {7, 7, 7, 7, 7, 7,7,7 ,7 ,7, 7, 7, 7};// len 13 shold go in slot: 5
    my_write(addr7, data7, DATA_7_SIZE, memory );

    memory->printData();


    // allocate slot bigger than any limit i.e > MAX_NUM
    cout << "Allocating bigger value than any slot size shold fail" << endl;
    my_malloc(22, memory, "addr8 22");



    cout << " \n\n -------- Final Snapshot Of Data ---------\n\n " << endl;
    memory->printData();

    delete memory; // call the deconstructor of the object


















}
