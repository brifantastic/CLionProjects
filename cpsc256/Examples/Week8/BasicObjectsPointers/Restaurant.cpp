#include "Restaurant.h"

// Default constructor:
// 1.  Initialize all private variables to some default value.
// 2.  In the case of the member variable id, initialize it to the static member variable nextID.
// 3.  Increment nextID so that the next object created will have a different id.

//Restaurant::Restaurant() {
//    name = "No Name";
//    rating = -1;
//    price = "No Price";
//    cuisine = "No Type";
//    id = nextID;
//    ++nextID;
//}

// Initialization constructor:
// 1.  Initialize all private variables to the values passed in as parameters.
// 2.  In the case of the member variable id, initialize it to the static member variable nextID.
// 3.  Increment nextID so that the next object created will have a different id.

Restaurant::Restaurant(string userName, int userRating, string price, string cuisineType) {
    name = userName;
    rating = userRating;
    this->price = price;  // We use the keyword "this" to distinguish between
                          // the internal 'price' variable of the class, and
                          // the external 'price' variable that is used for
                          // initialization.
                          // 
                          // You might think we could have been smarter and not
                          // had this duplication in the first place, and you would
                          // be correct!  But, still, in large projects, it can
                          // happen!
    cuisine = cuisineType;
    
    id = nextID;
    ++nextID;
}

// Static member variables are defined outside of the class definition!!!
// They are initialized to some value, and then can be used by all objects
// of the class.  In this case, we are using it to assign unique id values
// to each object of the class.

int Restaurant::nextID = 1001;

// Mutator functions ... used to change the values of private member variables.
// Note that we do not need to use the keyword "this" in this case, because
// the parameter names are different from the member variable names.

void Restaurant::SetName(string restaurantName) {
    name = restaurantName;
    return;
}

void Restaurant::SetRating(int rating) {
    this->rating = rating; //Need to specify this->rating to remove confusion with parameter name
    return;
}

void Restaurant::SetPrice(string price) {
    this->price = price;
    return;
}

void Restaurant::SetCuisineType(string cuisineType) {
    cuisine = cuisineType;
    return;
}

// Accessor functions ... used to return the values of private member variables.
// In this example, we do not have any of these, because they are all
// inline functions defined in the class definition (in the header file).


// Print function ... used to print the values of private member variables.
void Restaurant::Print() const {
    cout << name << ": " << "ID = " << id << endl;
    cout << "Rating = " << rating << " Price = " << price << " Cuisine Type = " 
            << cuisine << endl; 
}


