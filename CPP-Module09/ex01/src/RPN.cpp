#include "RPN.hpp"

RPN::RPN(){}
RPN::~RPN(){}

RPN::RPN(const RPN& other){
	*this = other;
}

RPN& RPN::operator=(const RPN& other){
	if (this != &other) {
		this->_stack = other._stack;
	}
	return *this;
}

void	RPN::set_stack(int n) {
	_stack.push(n);

	// #ifdef DEBUG
	// 	std::cout << "size:" << _stack.size() << std::endl;
	// #endif
}

int		RPN::get_stack(void) {
	if (isEmpty())
		throw std::runtime_error("not enough operands");

	int	ret = _stack.top();
	_stack.pop();
	return ret;
}

bool	RPN::isEmpty(void) const {
	return _stack.empty();
}

bool	RPN::is_command(char command) {
	if ('+' == command)
		return true;
	if ('-' == command)
		return true;
	if ('*' == command)
		return true;
	if ('/' == command)
		return true;
	return false;
}

void	RPN::run_command(char command) {
	int	n1, n2;
	n1 = get_stack();
	n2 = get_stack();

	if (command == '+') {
		#ifdef DEBUG
			std::cout << n2 << " + " << n1 << " = " << n2 + n1  << std::endl;
		#endif
		_stack.push(n2 + n1);
	}
	else if (command == '-') {
		#ifdef DEBUG
			std::cout << n2 << " - " << n1 << " = " << n2 - n1  << std::endl;
		#endif
		_stack.push(n2 - n1);
	}
	else if (command == '*') {
		#ifdef DEBUG
			std::cout << n2 << " * " << n1 << " = " << n2 * n1 << std::endl;
		#endif
		_stack.push(n2 * n1);
	}
	else if (command == '/') {
		#ifdef DEBUG
			std::cout << n2 << " / " << n1 << " = " << std::endl;
		#endif
		if (n1 == 0)
			throw std::runtime_error("division by zero");
		#ifdef DEBUG
			std::cout << n2 / n1 << std::endl;
		#endif
		_stack.push(n2 / n1);
	}
}
