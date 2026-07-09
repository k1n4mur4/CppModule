#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>
# include <iostream>
# include <limits>
# include <ctime>
# include <cstdlib>
# include <iomanip>
# include <cctype>
#include <stdexcept>
# ifndef DEBUG
#  define DEBUG 0
# endif

class PmergeMe
{
	private:
		std::vector<std::vector<int> >	_vec;
		std::vector<std::vector<int> >	_ans_vec;
		std::deque<std::deque<int> >	_deq;
		std::deque<std::deque<int> >	_ans_deq;
		double							_elapsed_vec;
		double							_elapsed_deq;
		bool							_measuredVector;
		bool							_measuredDeque;

		void				sortVector(int argc, char *argv[]);
		void				sortDeque(int argc, char *argv[]);
		int					jacobsthal(int n);
		double				getElapsedVector(void);
		void				setElapsedVector(double elapsed);
		double				getElapsedDeque(void);
		void				setElapsedDeque(double elapsed);
		void				pushDeque(const std::deque<int>& n);
		void				pushVector(const std::vector<int>& n);
		void				parseVector(int argc, char *argv[]);
		void				parseDeque(int argc, char *argv[]);

		std::string::size_type	getSizeVector(void);
		std::string::size_type	getSizeDeque(void);

		template<typename T>
		T lowerBound(T first, T last, int val);
		std::vector<std::vector<int> >				mergeInsertVector(std::vector<std::vector<int> >& origin);
		std::deque<std::deque<int> >				mergeInsertDeque(std::deque<std::deque<int> >& origin);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();
		void	sortAll(int argc, char *argv[]);
		void	printTimeVector(void);
		void	printTimeDeque(void);
		void	printVector(std::string msg);
		void	printDeque(std::string msg);
};

template<typename T>
T PmergeMe::lowerBound(T first, T last, int val)
{
	while (first < last) {
		T mid = first + (last - first) / 2;
		if (mid->back() < val) {
			first = mid + 1;
		} else {
			last = mid;
		}
	}
	return first;
}

#endif

