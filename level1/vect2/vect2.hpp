#pragma once


#include <iostream>

class vect2
{
	private:
		int x;
		int y;

		
		
	public:
		vect2() : x(0), y(0){}
		vect2(int a, int b) : x(a), y(b){}
		vect2(const vect2& copy)
		{
			x = copy.x;
			y = copy.y; 
		}
		vect2& operator=(const vect2& other)
		{
			if (this == &other)
				return *this;
			this->x = other.x;
			this->y = other.y;
			return *this;
		}

		int&	operator[](int item)
		{
			return (item == 0 ? x : y);
		}

		int	operator[](int item) const
		{
			return (item == 0 ? x : y);
		}

//         std::cout << "{" << v[0] << ", " << v[1] << "}" << std::endl;

		friend std::ostream& operator<<(std::ostream& os, vect2 toPrint)
		{
			os << "{" << toPrint.x << ", " << toPrint.y << "}"; 
			return os;
		}


		vect2 operator++()
		{
			x++; 
			y++;
			return *this;
		}
		vect2 operator++(int)
		{
			vect2 temp = *this;
			x++; 
			y++;
			return temp;
		}
		
		vect2 operator--()
		{
			x--; 
			y--;
			return *this;
		}
		vect2 operator--(int)
		{
			vect2 temp = *this;
			x--; 
			y--;
			return temp;
		}




		const vect2	operator*(int num) const  // * const const
		{
            		return vect2(x * num, y * num);
		}


		vect2 operator+(const vect2& other) const
		{
			return vect2(x + other.x, y + other.y);
		}

		vect2 operator-(const vect2& other)
		{
			return vect2(x - other.x, y - other.y);
		}

        	const vect2 operator-() const
		{
           		 return vect2(-x, -y);
		}
		vect2&	operator*=(int num)   //tik
		{
			x *= num; 
			y *= num;
			return *this;
		}
		vect2& operator+=(const vect2& other)  //tik
		{
			x += other.x; 
			y += other.y;
			return *this;
		}
		vect2& operator-=(const vect2& other)  //tik
		{
			x -= other.x; 
			y -= other.y;
			return *this;
		}

	
		friend const vect2  operator*(int num, const vect2& v)
		{
			return  vect2(v.x *num, v.y *num);
		}


		bool operator==(const vect2& other) const  //tik
		{
            return (x == other.x && y == other.y);
		}

		bool operator!=(const vect2& other) const  //tik
		{ 
            return (x != other.x || y != other.y);
		}

};

