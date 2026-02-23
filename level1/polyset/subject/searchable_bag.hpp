#pragma once

#include "bag.hpp"

class searchable_bag : virtual public bag { // searchable_bag inherits from bag
public:
	virtual bool has(int) const = 0; // this is a pure virtual function responsible to return true if the bag contains the item (searching the bag)
};
