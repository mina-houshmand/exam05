#include "bigint.hpp"


bigint::bigint()
{
	number = "0";
}

bigint::bigint(unsigned int num)
{
	if (num  == 0 )
	{
		number = "0";
		return ;
	}
	else
	{
		number.clear();
		while(num > 0)
		{
			number.push_back(char((num % 10) + '0'));
			num = num / 10;
		}
		std::reverse(number.begin(), number.end());
	}
}

bigint::bigint(std::string num)
{
	number = num;
}

bigint::bigint(const bigint& copy)
{
	number = copy.number;
}

bigint& bigint::operator=(const bigint& other)
{
	if(*this == other)
		return *this;
		
	number = other.number;
	return *this;
}



//getter
const std::string	bigint::getNum() const
{
	return number;
}

// addition
bigint	bigint::operator+ (const bigint& other)const
{
	std::string leftNumber = this->number;
	std::string rightNumber = other.number;


	int leftIndex = leftNumber.size() - 1;              // -1 because we want to start from the last digit
	int rightIndex = rightNumber.size() - 1;

	std::string result;
	result.reserve(leftIndex > rightIndex ? leftIndex + 1 : rightIndex + 1);   //we reserve for result in the size of the longest number + 1 for the carry

	int carry = 0;
	while (leftIndex >= 0 || rightIndex >= 0 || carry) // we continue while there are digits to add or a carry
	{
		int leftDigit = leftIndex >= 0 ? leftNumber[leftIndex] - '0' : 0;      // if there are a digits in rightNumber, we store the digit in leftDigit, otherwise we store 0
		int rightDigit = rightIndex >= 0 ? rightNumber[rightIndex] - '0' : 0;  //
		
		int digitSum = leftDigit + rightDigit + carry;                         // we add the most left digits from leftNumber and rightNumber and the carry

		result.push_back((digitSum % 10) + '0');                       //we convert the most right digit of the digitSum to a char and add it to the result

		carry = digitSum / 10;                                         // we store the most left digit of the digitSum in the carry variable

		leftIndex--;                                                // we move to the next digit (from right to left)
		rightIndex--;                                                
	}

	std::reverse(result.begin(), result.end());                   // we reverse the result to get the correct order of the digits

	bigint resultBigint(result);                                  // we create a new bigint with the result using the bigint(std::string n) constructor.
	return resultBigint;
}
bigint	bigint::operator+=(const bigint& other)
{
	*this = *this + other;
	return *this;
}

bigint	bigint::operator++(void)
{
	*this = *this + bigint(1);
	return *this;
}

bigint	bigint::operator++(int)
{
	bigint temp(*this);
	*this = *this + bigint(1);
	return temp;
}




// comparision
// comparision
bool	bigint::operator>(const bigint& other) const
{
    if (number.size() > other.number.size())
            return true;
    if (number.size() == other.number.size())
            return (number > other.number);

    return false;
}

bool	bigint::operator<(const bigint& other) const
{
    return (other > *this);
}


bool	bigint::operator>=(const bigint& other) const
{
    if (number.size() > other.number.size())
            return true;
    if (number.size() == other.number.size())
            return (number >= other.number);

    return false;
}

bool	bigint::operator<=(const bigint& other) const
{
    return (other >= *this);
}

        
bool	bigint::operator==(const bigint& other) const
{
    return (number == other.number);
}

bool	bigint::operator!=(const bigint& other) const
{
    return (number != other.number);
}

		// shifter
bigint	bigint::operator<<(unsigned int shift)
{
	bigint temp(*this);
	while (shift)
	{
		temp.number.push_back('0');
		shift--;
	}

	return temp;
}

bigint	bigint::operator>>(unsigned int shift)
{
	if (shift >= number.size())
		return (bigint("0"));

	bigint temp(*this);
	while(shift)
	{
		temp.number.resize(temp.number.size() - 1);
		shift--;
	}
	return temp;
}

		
bigint	bigint::operator<<=(unsigned int shift)
{
	*this = *this << shift;
	return *this;
}

bigint bigint::operator>>=(const bigint& shift)
{
    unsigned int s = shift.to_uint(); 
    *this = *this >> s;
    return *this;
}

unsigned int bigint::to_uint() const
{
    unsigned int result = 0;

    for (size_t i = 0; i < number.size(); ++i)
        result = result * 10 + (number[i] - '0');

    return result;
}

// bigint	bigint::operator>>=(unsigned int shift)
// {
// 	*this = *this >> shift;
// 	return *this;
// }

std::ostream&	operator<<(std::ostream& os, bigint toPrint)
{
	os << toPrint.getNum();
	return os;
}
