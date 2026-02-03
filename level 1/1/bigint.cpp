#include "bigint.hpp"
#include <cstdlib>

bigint::bigint(){           //dont forget bigint:: at first
	_number = "0";
}
	
bigint::bigint(unsigned int num){

	if (num == 0){
		_number = "0";     //add the value for _number
		return;
	}
	else
	{
		_number.clear();
		while(num > 0)
		{
			_number.push_back(char((num % 10) + '0'));
			num = num / 10;
		}
		std::reverse(_number.begin(), _number.end());   //carefull
	}
}

bigint::bigint(std::string num){
	_number = num;
}

bigint::bigint(const bigint& copy){
	_number = copy._number;
}


bigint& bigint::operator=(const bigint& other){  //carefull
	if(*this == other)
		return *this;
	_number = other._number;
	return *this;
}

const std::string bigint::getnum()const{
	return _number;
}


bigint bigint::operator+(const bigint& other)const{
	std::string leftnum = this->_number;
	std::string rightnum = other._number;
	std::string result;
	int carry = 0;
	
	int left_index = leftnum.size() - 1;
	int right_index = rightnum.size() - 1;
	
	while(left_index >= 0 || right_index >= 0 || carry)
	{
		int left_digit = left_index >= 0 ? leftnum[left_index] - '0' : 0;
		int right_digit = right_index >= 0 ? rightnum[right_index] - '0' : 0;
		int sum = left_digit + right_digit + carry;
		
		result.push_back((sum % 10) + '0');
		carry = sum / 10;
		
		left_index--;
		right_index--;
	}
	std::reverse(result.begin(), result.end());
	bigint resultbig(result);
	
	return resultbig;
}


bigint bigint::operator+=(const bigint& other){
	*this = *this + other;
	return *this;
}
	
bigint bigint::operator++(void){
	*this = *this + bigint(1);
	return *this;
}

bigint bigint::operator++(int){   //carefull return the old value
	bigint temp(*this);
	*this = *this + bigint(1);
	return (temp);
}


bool bigint::operator>(const bigint& other)const{
	if (this->_number.size() > other._number.size())
		return true;
	else if (this->_number.size() == other._number.size()){
		return (this->_number > other._number);
	}
	return false;
}

bool bigint::operator>=(const bigint& other)const{
	if (this->_number.size() > other._number.size())
		return true;
	else if (this->_number.size() == other._number.size()){
		return (this->_number >= other._number);
	}
	return false;
}


bool bigint::operator<(const bigint& other)const{
	return (other > *this);
}

bool bigint::operator<=(const bigint& other)const{
	return (other >= *this);
}

bool bigint::operator==(const bigint& other)const{
	return (_number == other._number);    //check this
}

bool bigint::operator!=(const bigint& other)const{
	return (_number != other._number);    //check this
}


bigint bigint::operator<<(unsigned int shift){
	bigint temp(*this);
	while(shift){
		temp._number.push_back('0');   //carefull .number and '0'
		shift--;
	}
	return temp;
}

bigint bigint::operator>>(unsigned int shift){
	if (shift >= this->_number.size())
		return (bigint("0"));
	bigint temp(*this);
	temp._number.resize(_number.size() - shift);
	
	
	return temp;
}


bigint bigint::operator<<=(unsigned int shift){
	*this = *this << shift;
	return *this;
	}
	
bigint bigint::operator>>=(unsigned int shift){
	*this = *this >> shift;
	return *this;
}

bigint bigint::operator<<(const bigint& shift){
	return *this << (unsigned int)std::atoi(shift.getnum().c_str());
}

bigint bigint::operator>>(const bigint& shift){
	return *this >> (unsigned int)std::atoi(shift.getnum().c_str());
}

bigint bigint::operator<<=(const bigint& shift){
	return *this <<= (unsigned int)std::atoi(shift.getnum().c_str());
}

bigint bigint::operator>>=(const bigint& shift){
	return *this >>= (unsigned int)std::atoi(shift.getnum().c_str());
}

std::ostream& operator<<(std::ostream& os, bigint toPrint){
	os << toPrint.getnum();
	return os;
	}




	
	

