/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on September 27, 2021, 2:56 PM
 */

#include <stdio.h>
#include <stdlib.h>

#include "PointerCar.h"

/*
 * This is the main program for the PointerCar example
 *
 * In comparison to the SimpleCar example, we will now
 * use pointers to structs, rather than the structs themselves.
 *
 * This will allow us to manipulate the structs directly, rather
 * than making copies of the structs.  This decreases the amount
 * of memory used, and also allows us to update the structs
 * directly.
 *
 */
int main(int argc, char** argv) {

    // Get information from the user - number of miles to drive forward,
    // and the number of miles to drive in reverse.
   int milesForward, milesReverse;
   printf("Miles forward = ");
   scanf("%d", &milesForward);
   printf("\n");
   printf("Miles reverse = ");
   scanf("%d", &milesReverse);
   printf("\n");

    // Initialize a new PointerCar struct, called myCar
   PointerCar myCar = InitCar();

    // We will now create a pointer to the myCar struct, and use that
    // pointer to manipulate the struct directly.
   PointerCar* pCar = &myCar;

   // We will now use the pointer to the struct to access the struct
   // directly, and print out the address of the struct, and the
   // mileage of the car (initially - should be zero!)
   printf("\n");
   printf("In main 1:  address of myCar = %p\n", pCar);
   printf("Mileage = %d\n", GetOdometer(pCar));
   printf("\n");

    // Drive forward by a specified amount
   Drive(milesForward, pCar);
   printf("\n");
   printf("In main 2:  address of myCar = %p\n", pCar);
   printf("Mileage = %d\n", GetOdometer(pCar));
   printf("\n");

    // Drive in reverse by a specified amount
   Reverse(milesReverse, pCar);
   printf("\n");
   printf("In main 3:  address of myCar = %p\n", pCar);
   printf("Mileage = %d\n", GetOdometer(pCar));
   printf("\n");

    // Change the make, model, and age of the car
   SetMake(pCar, "Mercedes-Benz");
   SetModel(pCar, "E350");
   SetAge(pCar, 16.0);

    // Call the HonkHorn and Report methods
   HonkHorn(pCar);   
   Report(pCar);

   return (EXIT_SUCCESS);
}

