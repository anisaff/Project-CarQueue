//
// Created by Anisa on 10/3/2019.
//

#ifndef ANISAFILFIL_HW4_CAR_H
#define ANISAFILFIL_HW4_CAR_H
#include <iostream>
using namespace std;

class Car {
private:
    int carNumber, arrivalTime, startTime, departureTime;
    int waitTime, totalTime;
public:
    Car();
    Car(int, int, int, int, int, int);

    // Getters
    int getCarNumber(){return carNumber;}
    int getArrivalTime(){return arrivalTime;}
    int getStartTime(){return startTime;}
    int getDepartureTime(){return departureTime;}
    int getWaitTime(){return waitTime;}
    int getTotalTime(){return totalTime;}

    //Setters
    void setCarNumber(int cn){carNumber = cn;}
    void setArrivalTime(int at){arrivalTime = at;}
    void setStartTime(int st){startTime = st;}
    void setDepartureTime(int dt){startTime = dt;}
    void setWaitTime(int wt){waitTime = wt;}
    void setTotalTime(int tt){totalTime = tt;}
};


#endif //ANISAFILFIL_HW4_CAR_H
