#include <iostream>

#include "Maths/Vector4.h"

int main()
{
	using namespace Dolmen;
#if 0
	std::cout << "Vector4 test:" << std::endl;
	std::cout << "Vector4 Addition Method:" << std::endl;

	std::cout << "Expected Result: ";
	{
		Vector4 a(2, 3, 10, 6);
		Vector4 b(4, 3, 5, 3);
		std::cout << a << " + " << b << " = (6, 6, 15, 9)" << std::endl;
		a.Add(b);
		std::cout << "Calculated Result: " << a << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Vector4 Subtration Method:" << std::endl;

	std::cout << "Expected Result: ";
	{
		Vector4 a(2, 3, 10, 6);
		Vector4 b(4, 3, 5, 3);
		std::cout << a << " - " << b << " = (-2, 0, 5, 3)" << std::endl;
		a.Subtract(b);
		std::cout << "Calculated Result: " << a << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Vector4 Multiplication Method:" << std::endl;

	std::cout << "Expected Result: ";
	{
		Vector4 a(2, 3, 10, 6);
		Vector4 b(4, 3, 5, 3);
		std::cout << a << " * " << b << " = (8, 9, 50, 18)" << std::endl;
		a.Multiply(b);
		std::cout << "Calculated Result: " << a << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Vector4 Division Method:" << std::endl;

	std::cout << "Expected Result: ";
	{
		Vector4 a(2, 3, 10, 6);
		Vector4 b(4, 3, 5, 3);
		std::cout << a << " / " << b << " = (0.5, 1, 2, 2)" << std::endl;
		a.Divide(b);
		std::cout << "Calculated Result: " << a << std::endl;
	}
	std::cout << std::endl;
#endif
#if 0
	std::cout << "Vector4 test:" << std::endl;
	std::cout << "Vector4 Addition operator:" << std::endl;

	std::cout << "Expected Result: ";
	{
		Vector4 a(2, 3, 10, 6);
		Vector4 b(4, 3, 5, 3);
		Vector4 c = a + b;
		std::cout << a << " + " << b << " = (6, 6, 15, 9)" << std::endl;		
		std::cout << "Calculated Result: " << c << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Vector4 Subtration operator:" << std::endl;

	std::cout << "Expected Result: ";
	{
		Vector4 a(2, 3, 10, 6);
		Vector4 b(4, 3, 5, 3);
		Vector4 c = a - b;
		std::cout << a << " - " << b << " = (-2, 0, 5, 3)" << std::endl;
		std::cout << "Calculated Result: " << c << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Vector4 Multiplication operator:" << std::endl;

	std::cout << "Expected Result: ";
	{
		Vector4 a(2, 3, 10, 6);
		Vector4 b(4, 3, 5, 3);
		Vector4 c = a * b;
		std::cout << a << " * " << b << " = (8, 9, 50, 18)" << std::endl;
		std::cout << "Calculated Result: " << c << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Vector4 Division operator:" << std::endl;

	std::cout << "Expected Result: ";
	{
		Vector4 a(2, 3, 10, 6);
		Vector4 b(4, 3, 5, 3);
		Vector4 c = a / b;
		std::cout << a << " / " << b << " = (0.5, 1, 2, 2)" << std::endl;
		std::cout << "Calculated Result: " << c << std::endl;
	}
	std::cout << std::endl;
#endif
#if 0
	std::cout << "Vector4 test:" << std::endl;
	std::cout << "Vector4 += operator:" << std::endl;

	std::cout << "Expected Result: ";
	{
		Vector4 a(2, 3, 10, 6);
		Vector4 b(4, 3, 5, 3);
		std::cout << a << " + " << b << " = (6, 6, 15, 9)" << std::endl;
		a += b;
		std::cout << "Calculated Result: " << a << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Vector4 -= operator:" << std::endl;

	std::cout << "Expected Result: ";
	{
		Vector4 a(2, 3, 10, 6);
		Vector4 b(4, 3, 5, 3);
		std::cout << a << " - " << b << " = (-2, 0, 5, 3)" << std::endl;
		a -= b;
		std::cout << "Calculated Result: " << a << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Vector4 *= operator:" << std::endl;

	std::cout << "Expected Result: ";
	{
		Vector4 a(2, 3, 10, 6);
		Vector4 b(4, 3, 5, 3);
		std::cout << a << " * " << b << " = (8, 9, 50, 18)" << std::endl;
		a *= b;
		std::cout << "Calculated Result: " << a << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Vector4 /= operator:" << std::endl;

	std::cout << "Expected Result: ";
	{
		Vector4 a(2, 3, 10, 6);
		Vector4 b(4, 3, 5, 3);
		std::cout << a << " / " << b << " = (0.5, 1, 2, 2)" << std::endl;
		a /= b;
		std::cout << "Calculated Result: " << a << std::endl;
	}
	std::cout << std::endl;
#endif
#if 1
	std::cout << "Vector4 test:" << std::endl;
	std::cout << "Vector4 == operator:" << std::endl;

	std::cout << "Expected Result: ";
	{
		Vector4 a(2, 3, 4, 5);
		Vector4 b(2, 3, 4, 5);
		Vector4 c(3, 3, 6, 9);

		std::cout << a << " == " << b << " = 1 (true)" << std::endl;
		std::cout << "Calculated Result: " << (a == b) << std::endl;
		std::wcout << std::endl;
		std::cout << a << " == " << c << " = 0 (false)" << std::endl;
		std::cout << "Calculated Result: " << (a == c) << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Vector4 != operator:" << std::endl;

	std::cout << "Expected Result: ";
	{
		Vector4 a(2, 3, 4, 5);
		Vector4 b(2, 3, 4, 5);
		Vector4 c(3, 3, 6, 9);

		std::cout << a << " != " << c << " = 1 (true)" << std::endl;
		std::cout << "Calculated Result: " << (a != c) << std::endl;
		std::wcout << std::endl;
		std::cout << a << " != " << b << " = 0 (false)" << std::endl;
		std::cout << "Calculated Result: " << (a != b) << std::endl;
	}
	std::cout << std::endl;
#endif

	std::cin.get();
}