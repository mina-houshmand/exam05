#pragma once //modern way to prevent multiple inclusions

class bag {                                         // it is our abstract class that will be inherited by our other classes
public:
	virtual void insert (int) = 0;                  // this = 0 has 2 effects:
													// 1. it makes the function pure virtual meaning for all classes that inherit from bag, they must implement this function
													// 2. it makes the class abstract meaning, we cannot create an instance of bag
	virtual void insert (int *, int) = 0;
	virtual void print() const = 0;
	virtual void clear() = 0;
};
