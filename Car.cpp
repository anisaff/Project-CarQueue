//
// Created by Anisa on 10/3/2019.
//

#include "Car.h"

Car::Car()
{
}

Car::Car(int cn, int ar, int st, int dt, int wt, int tt)
{
    carNumber = cn;
    arrivalTime = ar;
    startTime = st;
    departureTime = dt;
    waitTime = wt;
    totalTime = tt;
}
