#include <iostream>
#include "Bureaucrat.hpp"

int main() {
	// success
	try {
		Bureaucrat b("Alice", 75);
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// float
	try {
		Bureaucrat b("float", 1.0);
		std::cout << b << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// error
	// High Limit
	try {
		Bureaucrat b("HighLimit", 1);
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

		// Low Limit
	try {
		Bureaucrat b("LowLimit", 150);
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// high
	try {
		Bureaucrat b("High", 0);
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	// low
	try {
		Bureaucrat b("Low", 151);
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}
