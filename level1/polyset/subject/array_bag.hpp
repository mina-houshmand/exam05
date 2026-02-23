#pragma once

#include "bag.hpp"

class array_bag : virtual public bag // here we are defining array_bag class that inherits public and protectedmembers and methods from bag class
                                     // because of 'virtual', if multiple classes in the hierarchy inherit from bag,
                                     // only one shared instance of bag will exist in the final derived class
									 // we will never have more than one instance of bag in the hierarchy

{
 protected:                          // protected members are accessible to the class itself and its derived classes
	int *data;                       // array of integers
	int size;                        // size of the array

 public:                             
	array_bag();                      // constructor
	array_bag(const array_bag &);     // copy constructor
	array_bag &operator=(const array_bag &other);   // assignment operator
	~array_bag();                                   // destructor

	void insert(int);                               //insert an integer at the end of the array
	void insert(int *, int);                        //insert an array of integers at the end of our current array
	void print() const;                             //we print the elements of the array
	void clear();                                   // we clear the array and set the size to 0
};
