#include "Span.hpp"
#include <algorithm>

Span::Span() : _maxSize(0) {}

Span::~Span() {}

Span::Span(unsigned int n) : _maxSize(n) {
	_numbers.reserve(n);
}

Span::Span(const Span& other) {
	*this = other;
}

Span&	Span::operator=(const Span& other) {

	if (this != &other) {
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}

	return *this;
}

int		Span::shortestSpan() const {

	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers");

	std::vector<int> sorted = _numbers; 
	std::sort(sorted.begin(), sorted.end());
	
	int	shortest = sorted[1] - sorted[0];
	for (size_t i = 1; i < sorted.size(); ++i) {
		int diff = sorted[i] - sorted[i - 1];
		if (diff < shortest)
			shortest = diff;
	}

	return shortest;
}

int		Span::longestSpan() const {

	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers");

	int	max = *std::max_element(_numbers.begin(), _numbers.end());
	int	min = *std::min_element(_numbers.begin(), _numbers.end());

	return max - min;
}

void	Span::addNumber(int n) {

	if (_numbers.size() >= _maxSize)
		throw std::out_of_range("Span is full");

	_numbers.push_back(n);
}
