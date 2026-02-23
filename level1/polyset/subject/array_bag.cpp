#include "array_bag.hpp"
#include <iostream>

array_bag::array_bag() {
  size = 0;
  data = nullptr;
}

array_bag::array_bag(const array_bag &src) {
  size = src.size;                                  // copy the size of the array
  data = new int[size];                             // allocate memory for the array
  for (int i = 0; i < size; i++) {                  // copy the elements of the array
	data[i] = src.data[i];
  }
}

array_bag &array_bag::operator=(const array_bag &src) {
	if (this != &src) {                 // if the array is not the same and exists we delete it and create a new one and copy the elements to it
		if (data != nullptr) {
			delete[] data;
			data = nullptr;
		}
		size = src.size;
		data = new int[size];
		for (int i = 0; i < size; i++) {
			data[i] = src.data[i];
		}
	}
	return *this;
}

array_bag::~array_bag() {
	if (data != nullptr) {                      // if the array exists we delete it
		delete[] data;
		data = nullptr;
	}
}

void array_bag::insert(int item) {
	int *new_data = new int[size + 1];             // we create a new array with one more element than the current one
	for (int i = 0; i < size; i++) {               // we loop through the current array and copy the elements to the new array
		new_data[i] = data[i];
	}
	new_data[size] = item;                         // we add the new element at the end of the array
	if (data != nullptr) {                         // if the current array exists we delete it
		delete[] data;
	}
	data = new_data;                               // we assign the new array to the current array
	size++;                                        // we increment the size of the array
}

void array_bag::insert(int *items, int count) {    // we receive an array of integers and the number of elements in the array
	int *new_data = new int[size + count];         // we create a new array with size of the current array + the number of elements in the array we receive
	for (int i = 0; i < size; i++) {               // we loop through the current array and copy the elements to the new array
		new_data[i] = data[i];                     // we copy the elements of the current array to the new array
	}
	for (int i = 0; i < count; i++) {              
		new_data[size + i] = items[i];
	}
	if (data != nullptr) {
		delete[] data;
	}
	data = new_data;
	size += count;
}

void array_bag::print() const {                     // we print the elements of the array
	for (int i = 0; i < size; i++) {               
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}

void array_bag::clear() {                           // we clear the array and set the size to 0
	if (data != nullptr) {
		delete[] data;
		data = nullptr;
	}
	size = 0;
}
