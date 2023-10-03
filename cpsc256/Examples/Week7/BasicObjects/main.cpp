/*
 * Basic Objects
 */

/* 
 * File:   main.cpp
 * Author: brash
 *
 * Created on October 25, 2021, 12:46 PM
 */

#include <vector>

#include "Restaurant.h"

Restaurant getFavorite(vector<Restaurant> myRestaurants);

int main(int argc, char** argv) {
    
    // Define some objects ... the first two call the default constructor, and the last
    // calls the initialization constructor.
    Restaurant schooners; // default values, id = 1001
    Restaurant moes; // default values, id = 1002
    Restaurant mickydees("MacDonald's",-10000,"$","Fast Food"); // specified values, id = 1003
    
    cout << "Initial Definition of MacDonald's" << endl;
    mickydees.Print();
    cout << endl;
    
    cout << "Initial Definition of Schooner's" << endl;
    schooners.Print();
    cout << endl;
    
    schooners.SetName("Schooner's");
    schooners.SetRating(4);
    schooners.SetPrice("$$$");
    schooners.SetCuisineType("American Fare");
    
    cout << "New Definition of Schooner's" << endl;
    schooners.Print();
    cout << endl;
    
    cout << "Initial Definition of Moe's" << endl;
    moes.Print();
    cout << endl;
    
    moes.SetName("Moe's");
    moes.SetRating(5);
    moes.SetPrice("$$");
    moes.SetCuisineType("Mexican");
    
    cout << "New Definition of Moe's" << endl;
    moes.Print();
    cout << endl;
    
    // Define a vector of Restaurant objects, and add our three restaurants to it!!!
    vector<Restaurant> myRestaurants;
    
    myRestaurants.push_back(schooners);
    myRestaurants.push_back(moes);
    myRestaurants.push_back(mickydees);
    
    // Figure out the restaurant with the highest rating.
    Restaurant myFavorite;
    
    cout << "Address of myRestaurants in main:  " << &myRestaurants << endl;
    myFavorite = getFavorite(myRestaurants);
    
    cout << "My favorite restaurant: " << endl;
    cout << myFavorite.GetName() << endl;
    cout << "Rating = " << myFavorite.GetRating() << endl;
    cout << "Price = " << myFavorite.GetPrice() << endl;
    cout << "Cuisine Type = " << myFavorite.GetCuisineType() << endl;
    cout << endl;

    cout << "Address of myFavorite in main:  " << &myFavorite << endl;
    cout << "Address of myRestaurants[1] in main:  " << &myRestaurants[1] << endl;

    // Change one of the internal values of the Moe's object in the vector
    // and see if it changes the value in the myFavorite object.

    myRestaurants[1].SetRating(1);

    cout << "My favorite restaurant: " << endl;
    cout << myFavorite.GetName() << endl;
    cout << "Rating = " << myFavorite.GetRating() << endl;
    cout << "Price = " << myFavorite.GetPrice() << endl;
    cout << "Cuisine Type = " << myFavorite.GetCuisineType() << endl;

    
    return 0;
}

Restaurant getFavorite(vector<Restaurant> myRestaurants) {
    
    cout << "Address of my Restaurants in getFavorite:  " << &myRestaurants << endl;
    cout << endl;
    
    Restaurant bestRestaurant;
    
    int maxRatingIndex = 0;
    int maxRating = -1000000;
    
    cout << "Ratings:" << endl;
    for (int i = 0; i<myRestaurants.size(); i++) {
        myRestaurants[i].Print();
        if (myRestaurants[i].GetRating() > maxRating) {
            maxRatingIndex = i;
            maxRating = myRestaurants[i].GetRating();
        }
    }
    cout << endl;

    // Extract the best restaurant from the vector of restaurant objects
    //
    // Note that we are using the assignment operator here ...
    // we are copying the contents of the object in the vector to the
    // object bestRestaurant.  This is a shallow copy, and we will
    // discuss this in class.
    //
    // Shallow copy:
    // A shallow copy copies the contents of the object, but does not
    // copy any pointers that might be in the object.  In this case,
    // we are copying the contents of the object. If we had a pointer
    // in the object, we would be copying the pointer, but not the
    // contents of the object that the pointer points to!!!
    //
    // Note that when we are dealing with objects that contain pointers, we need
    // to be careful about how we copy objects.  We will discuss this
    // in class, as well!!!

    bestRestaurant = myRestaurants[maxRatingIndex];
    cout << "Address of bestRestaurant in getFavorite:  " << &bestRestaurant << endl;
    cout << "Address of myRestaurants[maxRatingIndex] in getFavorite:  " << &myRestaurants[maxRatingIndex] << endl;
    
    return bestRestaurant;
    
}

