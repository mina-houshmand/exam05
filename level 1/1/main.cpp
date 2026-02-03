//-Requirements derived from main()

//-We need a class called bigint.
//             Constructors:

// - A default constructor → should initialize to 0.
//We know this because in bigint c; later, printing c should output 0.
//A constructor from int / unsigned int → e.g. bigint a(42); and bigint b(21);.
//A copy constructor → used in bigint e(d);.
//          Output support:

//Must overload operator<< for std::ostream.
//Because we have lines like std::cout << a << std::endl;.

//           Arithmetic operators:

//operator+ for bigint + bigint.
//Needed for "a + b = " << a + b.
//operator+= for bigint.
//Needed for (c += a).

//           Increment operators:

//Pre-increment ++b.
//Post-increment b++.
//They must behave the same way as built-in int increments.

//           Comparison operators:
//operator<, operator>, operator==, operator!=, operator<=, operator>=.
//Because we test (d < a), (d > a), (d == a), etc.
//Shift operators (bigint style):
//operator<< (unsigned int) → should simulate base-10 "multiply by 10^shift".
//e.g. (x << 2) prints 123400.
//operator>> (unsigned int) → should simulate base-10 "divide by 10^shift" (truncate).
//e.g. (x >>= 2) prints 12.
//Compound assignment versions <<= and >>= (in-place modification).
//Because we call (d <<= 4) and (d >>= 2).

//               Requirements implied by the solution structure

//Internal representation:
//A std::string number to store digits.
//This avoids int overflow, and allows arbitrary size numbers.

//Assignment operator:
//operator= is needed, since we use *this = *this + other.

//Getter:
//getNum() returning the internal std::string, for printing.

//                    Details to respect:
//Addition must handle carries correctly (done digit by digit).
//Shifts (<<, >>) must add/remove zeros as strings, not binary shifts.
//Comparisons must compare by length first, then lexicographically if equal length.
//++ operators must work exactly like integers (pre vs post difference).

//✅ So, the full to-do list to satisfy the task is:

//Define a class bigint.
//Add member std::string number.
//Implement constructors:
//default → "0".
//from unsigned int.
//from std::string.
//copy constructor.
//Implement operator=.
//Implement operator<< for printing.
//Implement getNum() getter.
//Implement arithmetic:
//operator+.
//operator+=.
//Implement increments:
//pre-increment operator++().
//post-increment operator++(int).
//Implement comparisons:
//>, <, >=, <=, ==, !=.
//Implement base-10 shift operators:
//<<, >>.
//<<=, >>=.


#include "bigint.hpp"

//c++ -g --std=c++98 main.cpp bigint.cpp bigint.hpp && valgrind --leak-check=full --show-leak-kinds=all ./a.out
int	main(void)
{
	{
		const bigint	a(42);
		bigint			b(21), c, d(1337), e(d);
		
		//All are in base10
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
		std::cout << d << std::endl;
		std::cout << e << std::endl;
		std::cout << "a + b = " << a + b << std::endl; // a + b = 63
		std::cout << "(c += a) = " << (c += a) << std::endl; // c = 42, donc (c += a) = 42
		
		std::cout << "\n\n" << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << "++b = " << ++b << std::endl;
		std::cout << "b++ = " << b++ << std::endl;
		std::cout << "b = " << b << std::endl;
		int	i = 0;//checking**
		std::cout << "i = " << i << std::endl;
		std::cout << "++i = " << ++i << std::endl;
		std::cout << "i++ = " << i++ << std::endl;
		std::cout << "i = " << i << std::endl;

		std::cout << "\n\n" << std::endl;
		std::cout << "\"((b << 10) + 42)\" = " << ((b << 10) + 42) << std::endl;
		std::cout << "(d <<= 4) = " << (d <<= 4) << std::endl;
		std::cout << "(d >>= 2) = " << (d >>= 2) << std::endl;
		std::cout << "a = " << a << std::endl;
		std::cout << "d = " << d << std::endl;
		std::cout << "(d < a) = " << (d < a) << std::endl;
		std::cout << "(d > a) = " << (d > a) << std::endl;
		std::cout << "(d == a) = " << (d == a) << std::endl;
		std::cout << "(d != a) = " << (d != a) << std::endl;
		std::cout << "(d == d) = " << (d == d) << std::endl;
		std::cout << "(d <= a) = " << (d <= a) << std::endl;
		std::cout << "(d >= a) = " << (d >= a) << std::endl;

		bigint x(1234);
		std::cout << std::endl;
		std::cout << "\"(x << 2)\"--> " << (x << 2) << "\n";   // prints 123400
		std::cout << "\"(x >>= 2)\"--> " << (x >>= 2) << "\n";   // prints   12}
	}
	return (0);
}
