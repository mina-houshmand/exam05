#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <algorithm>

class bigint{
	private:
	std::string _number;
	public:
	bigint();
	bigint(unsigned int num);
	bigint(std::string num);
	bigint(const bigint& copy);
	bigint& operator=(const bigint& other);  //word operator
	
	bigint operator+(const bigint& other)const;  //two const important
	bigint operator+=(const bigint& other);

	bigint operator++(void);
	bigint operator++(int);
	
	bool operator>(const bigint& other)const;
	bool operator>=(const bigint& other)const;
	bool operator<(const bigint& other)const;
	bool operator<=(const bigint& other)const;
	bool operator==(const bigint& other)const;   //== is boolean
	bool operator!=(const bigint& othre)const;
	
	const std::string getnum()const; //two const!!
	
	bigint operator>>(unsigned int shift);  //unsigned int shift
	bigint operator<<(unsigned int shift);
	 
	bigint	operator<<=(unsigned int shift);  //dont forget these two
	bigint	operator>>=(unsigned int shift);
        
        
};

std::ostream& operator<<(std::ostream& os, bigint toPrint);



#endif


