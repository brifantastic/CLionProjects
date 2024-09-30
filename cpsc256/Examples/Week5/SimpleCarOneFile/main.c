/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/*
 * File:   main.c
 * Author: brash
 *
 * Created on September 26, 2021, 10:37 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SimpleCar_struct {
    int miles;
    double age;
    char make[20];
    char model[20];
} SimpleCar;

SimpleCar InitCar(){
    SimpleCar newCar;

    newCar.miles = 0;
    newCar.age = 0.0;
    strcpy(newCar.make, "Toyota");
    strcpy(newCar.model, "Camry");

    printf("In InitCar: address of newCar = %p\n",&newCar);

    return newCar;
}

// Getter and Setter Methods

int GetOdometer(SimpleCar car){
    return car.miles;
}

SimpleCar SetOdometer(SimpleCar car, int mileage){
    printf("In SetOdometer:  address of car = %p\n",&car);
    car.miles = mileage;
    return car;
}

double GetAge(SimpleCar car){
    return car.age;
}

SimpleCar SetAge(SimpleCar car, double age){
    printf("In SetAge:  address of car = %p\n",&car);
    car.age = age;
    return car;
}

char* GetMake(SimpleCar car){
    static char localmake[20];
    strcpy(localmake,car.make);
    return localmake;
}

SimpleCar SetMake(SimpleCar car, char* make){
    strcpy(car.make,make);
    printf("In SetMake: make = %s\n",car.make);
    return car;
}

char* GetModel(SimpleCar car){
    static char localmodel[20];
    strcpy(localmodel,car.model);
    return localmodel;
}

SimpleCar SetModel(SimpleCar car, char* model){
    strcpy(car.model,model);
    printf("In SetModel: model = %s\n",car.model);
    return car;
}

// Complex Methods

SimpleCar Drive(int dist, SimpleCar car){
    printf("In Drive:  address of car = %p\n",&car);

    int odometer = GetOdometer(car);
    int newOdometer = odometer + dist;
    car = SetOdometer(car, newOdometer);

    printf("In Drive: address of car = %p\n",&car);
    return car;
}

SimpleCar Reverse(int dist, SimpleCar car){
    printf("In Reverse:  address of car = %p\n",&car);

    int odometer = GetOdometer(car);
    int newOdometer = odometer - dist;
    car = SetOdometer(car, newOdometer);

    printf("In Reverse: address of car = %p\n",&car);
    return car;
}

void HonkHorn(SimpleCar car){
    printf("In HonkHorn: address of car = %p\n",&car);
    printf("beep beep\n");
}

void Report(SimpleCar car){
    printf("In Report: address of car = %p\n",&car);

    printf("Make of Car: %s\n",GetMake(car));
    printf("Model of Car: %s\n",GetModel(car));
    printf("Age of Car: %lf\n",GetAge(car));
    printf("Car has driven: %d miles\n", GetOdometer(car));
}


int main() {

    // The strategy in the main program should be that we ONLY call
    // the methods specified in SimpleCar.h!!  We don't manipulate the
    // internal variables of the struct directly ... this way, if we
    // decided to update/change/edit/evolve the internal structure
    // of SimpleCar objects, it will be largely transparent to the user.
    //
    // The user should be able to look at an API for SimpleCar,
    // which details the SimpleCar methods, and figure out
    // how to write the code!

    // -------------------------------------------------------------

    // Get information from the user - number of miles to drive forward,
    // and the number of miles to drive in reverse.
    //
    int milesForward, milesReverse;
    printf("Miles forward = ");
    scanf("%d", &milesForward);
    printf("\n");
    printf("Miles reverse = ");
    scanf("%d", &milesReverse);
    printf("\n");

    // Initialize a new SimpleCar struct, called myCar
    SimpleCar myCar = InitCar();
    printf("In main 1:  address of myCar = %p\n",&myCar);
    printf("Mileage = %d\n",GetOdometer(myCar));

    // Example of using the SetOdometer method and the GetOdometer method
    //myCar = SetOdometer(myCar,100);
    //printf("Mileage = %d\n",GetOdometer(myCar));

    // Drive forward by a specified amount
    myCar = Drive(milesForward,myCar);
    printf("In main 2:  address of myCar = %p\n",&myCar);
    printf("Mileage = %d\n",GetOdometer(myCar));

    // Drive in reverse by a specified amount
    myCar = Reverse(milesReverse,myCar);
    printf("In main 3:  address of myCar = %p\n",&myCar);
    printf("Mileage = %d\n",GetOdometer(myCar));

    // Change the make, model, and age of the car

    myCar = SetMake(myCar,"Mercedes-Benz");
    myCar = SetModel(myCar,"E350");
    myCar = SetAge(myCar,16.0);

    // Call the HonkHorn and Report methods
    HonkHorn(myCar);
    Report(myCar);

    return (EXIT_SUCCESS);

}