#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <iterator>
#include <stdexcept>

class Span {
	public:
		Span();
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		int		shortestSpan() const;
		int		longestSpan() const;

		void	addNumber(int n);

		template <typename InputIterator>
		void	addNumbers(InputIterator first, InputIterator last);

	private:
		unsigned int		_maxSize;
		std::vector<int>	_numbers;
};

template <typename InputIterator>
void	Span::addNumbers(InputIterator first, InputIterator last) {

	if (_numbers.size() + std::distance(first, last) > _maxSize)
		throw std::out_of_range("Span would overflow");

	_numbers.insert(_numbers.end(), first, last);
}

#endif
