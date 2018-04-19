Author - Aman Nagpal
email - amannagpal4@gmail.com

This program simulates a contigous memory


Defaults values for a memory slot

baseRegister = -1
default value for data is -1 in memory and memory slot
limitRegister = -1
endSlot = -1

whenever we print data we print data from Memory Class and not data in MemorySlot

The program by default runs on "Best Fit " to run using First Fit algorithm
        Change ALGO constant in "includes.h" to 1

If we cannot allocate a slot (size might be too big and slot not available) we return -1 which is default baseReg

To compile the code run the following command

g++ -std=c++11 Algorithm.cpp Driver.cpp Interface.cpp Memory.cpp MemorySlot.cpp Helper.cpp

I have also attached a compiled version of the program.

Please contact me on anagpal4@bu.edu if you have any queries
