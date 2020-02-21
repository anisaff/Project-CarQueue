***************************************************
* Class     :   CSCI 2421-001
* HW #      :   4
* Due Date  :   Oct. 14, 2019
**************************************************


                    READ ME


**************************************************
 *  Description of the program
**************************************************

This Program is a simulation of a car wash work day. It reads in the
times that cars show up to the car wash and saves them into a queue.
Based on the times that the cars show up and how only one car can
go through the car wash at a time, the program call on functions
to find the car number, arrival time, start time, departure time, etc.
These variables are save into a car object to access them when outputting
the car wash stats.

**************************************************
 *  Source files
**************************************************

Name: main.cpp
    The main program. This runs the program by reading arrival times
    in from a file and using function call and loops to find the
    desired stats for the car wash.

Name: Car.h
    Specification file. Contains the definition of the Car class.

Name: guess.cpp
    Implementation file. Implements the Car class.

**************************************************
 *  Circumstances of program
**************************************************

    The program runs successfully in Clion and Csegrid.

**************************************************
 *  How to build and run the program
**************************************************

1.  Homework file is compressed so first uncompress it.

    The directory is named AnisaFilfil_Hw4 with files:
        main.cpp
        Car.h
        Car.cpp
        makefile.txt
        ReadMe.txt

2.  Build the Program

     change directory:
     % cd [hw4]

     compile:
     % make

     run:
     % ./hw4
