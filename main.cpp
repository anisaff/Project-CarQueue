#include <iostream>
#include <fstream>
#include <queue>
#include <iomanip>
#include "Car.h"

using namespace std;

// Global Variable set for 540 minutes for total run time
int SIMULATION_END_TIME = 540;

//Function prototypes
int findArrivalTime(queue<int>&);
int findStartTime(int, Car&);
int findDepartureTime(int);
void output(Car numOfCars[], int);
int findWaitTime(int, int);
int findTotalTime(int);    // Total time car was in car wash

int main()
{
    // Declare variables
    int carNumber, arrivalTime, startTime;
    int departureTime, waitTime, totalTime;
    queue<int> q; // Queue to hold arrival times

    // Start reading in from file
    ifstream infile("arrival_time.txt");

    // Save arrival times in queue
    while(infile >> arrivalTime)
    {
        q.push(arrivalTime);
    }
    infile.close();

    int numOfCars = q.size();   //Find the size of the queue to find number of cars in line
    Car numCars[numOfCars];     //Array to hold the car objects
    // Loop to find all variables for car object then create the object and add to the car array
    for (int i = 1; i <= numOfCars; i++)
    {
        carNumber = i;
        arrivalTime = findArrivalTime(q);
        if (carNumber == 1)
            startTime = arrivalTime;
        else
            startTime = findStartTime(arrivalTime, numCars[i-2]);

        if (carNumber == 1)
            departureTime = startTime + 3;
        else
            departureTime = findDepartureTime(startTime);
        waitTime = findWaitTime(arrivalTime, startTime);
        totalTime = findTotalTime(waitTime);
        Car car(carNumber, arrivalTime, startTime, departureTime, waitTime, totalTime);     // Create car object to keep track of numbers
        numCars[i-1] = car;                                            // Add car object to array to save info
    }
    // Function to output the report for the car wash
    output(numCars, numOfCars);

    return 0;
}

// function returns arrival time
int findArrivalTime(queue<int> &q)
{
    int arrive;
    arrive = q.front();
    q.pop();
    return arrive;
}

// function returns start time
int findStartTime(int arrivalTime, Car& carBefore)
{
    int startTime;
    int arriveBefore = carBefore.getArrivalTime();
    int departBefore = carBefore.getDepartureTime();
    if (arrivalTime > SIMULATION_END_TIME)
        startTime = -1;
    else if (arrivalTime > departBefore)
        startTime = arrivalTime;
    else
        startTime = departBefore;

    return startTime;
}

// function returns departure time
int findDepartureTime(int startTime)
{
    int dep;
    if (startTime == 0)
        dep = 0;
    else
        dep = startTime + 3;
    return dep;
}

// function returns wait time
int findWaitTime(int arrivalTime, int startTime)
{
    int wait;
    if (startTime == 0)
        wait = 0;
    else
        wait = startTime - arrivalTime;
    return wait;
}

// function returns total time
int findTotalTime(int wait)
{
    int total;
    total = wait + 3;
    return total;
}

// Function outputs the data from the car wash
void output(Car numCars[], int size)
{
    // Variables to find total wait time, average wait time and percentage car wash was in use
    int carsServed = 0, totalWaitTime = 0, averageWaitTime;
    int washTime = 0;
    cout << "\nOpening Time: 8:00 AM (0 minutes) " << endl;
    cout << "Closing Time: 5:00 PM (540 minutes) " << endl;
    cout << "Start of Simulation\n";
    cout<< "\nCar Number " << "  " << "Arrival Time " << "  " << "Start Time "  << "  " << "Departure Time " << "   " << "Wait Time " << "    " << "Total Time" << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;

    // Loop to output stats
    for (int j = 0; j < size; j++)
    {
        cout << setw(5) << numCars[j].getCarNumber() << setw(15) << numCars[j].getArrivalTime() << setw(14);
        if (numCars[j].getStartTime() == -1)
            cout << "           Car arrived after closing time and was not served." << endl;
        else
            cout << numCars[j].getStartTime() << setw(15) << numCars[j].getDepartureTime() << setw(15)
            << numCars[j].getWaitTime() <<setw(15) << numCars[j].getTotalTime() << endl;
    }

    // For loop to total up the wait time
    for (int i = 0; i < size; i++)
    {
        if (numCars[i].getStartTime() != -1)
        {
            totalWaitTime += numCars[i].getWaitTime();
            carsServed++;
            washTime += 3;
        }
    }
    averageWaitTime = totalWaitTime / carsServed;
    double remainder = totalWaitTime % carsServed;
    int seconds = (remainder / carsServed) * 60 ;
    int percentage = (washTime * 100)/ SIMULATION_END_TIME;


    // Overall statistics for car wash
    cout << "\nEnd of Simulation" << endl;
    cout << "\nStatistics: " << endl;
    cout << "\nTotal wait time: " << totalWaitTime << " minutes"<< endl;
    cout << "Average wait time: " << averageWaitTime << " minutes and " <<  seconds << " seconds" << endl;
    cout << "Total car wash use time: " << washTime << " minutes" << endl;
    cout << "Percentage of time car wash was in use: " << percentage << "%" << endl;

}



