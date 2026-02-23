#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <algorithm>

class bigint
{
	private:
		std::string number;                         // we use a string to store the number because it is easier to manipulate than an integer

	public:
		bigint();                                   // default constructor
		bigint(unsigned int num);                   // constructor from an unsigned int
		bigint(std::string num);                    // constructor from a string
		bigint(const bigint& copy);                 // copy constructor
		bigint& operator=(const bigint& other);     // assignment operator


		//getter
		const std::string	getNum()const;          // getter for the number

		// addition
		bigint	operator+(const bigint& ohter)const;   // overload of the + operator
		bigint	operator+=(const bigint& ohter);       // overload of the += operator
		bigint	operator++(void);                      // overload of the ++ operator (pre-increment)
		bigint	operator++(int);	                   // overload of the ++ operator



		// comparision
		bool	operator>(const bigint& ohter) const; // overload of the > operator
		bool	operator<(const bigint& ohter) const; // overload of the < operator
		
		bool	operator>=(const bigint& ohter) const; // overload of the >= operator
		bool	operator<=(const bigint& ohter) const; // overload of the <= operator
		
		bool	operator==(const bigint& ohter) const; // overload of the == operator
		bool	operator!=(const bigint& ohter) const; // overload of the != operator


		// shifter
		bigint	operator<<(unsigned int shift); // overload of the << operator (simulate base-10 "multiply by 10^shift")
		bigint	operator>>(unsigned int shift); // overload of the >> operator (simulate base-10 "divide by 10^shift")
		
		bigint	operator<<=(unsigned int shift); // overload of the <<= operator (in-place modification)
		// bigint	operator>>=(unsigned int shift); // overload of the >>= operator (in-place modification)

		bigint operator>>=(const bigint& shift);
		unsigned int to_uint() const;
};

std::ostream&	operator<<(std::ostream& os, bigint toPrint); // overload of the << operator for the ostream

#endif