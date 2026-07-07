#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
	_vec.clear();
	_deq.clear();
	_measuredVector = false;
	_measuredDeque = false;
	_elapsed_vec = 0.0;
	_elapsed_deq = 0.0;
}

PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		_vec = other._vec;
		_ans_vec = other._ans_vec;
		_deq = other._deq;
		_ans_deq = other._ans_deq;
		_elapsed_vec = other._elapsed_vec;
		_elapsed_deq = other._elapsed_deq;
		_measuredVector = other._measuredVector;
		_measuredDeque = other._measuredDeque;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

void	PmergeMe::pushVector(const std::vector<int>& n) {
	_vec.push_back(n);
}

void	PmergeMe::pushDeque(const std::deque<int>& n) {
	_deq.push_back(n);
}

double	PmergeMe::getElapsedVector(void) {
	if (!_measuredVector) {
		throw std::runtime_error("not measured");
	}
	return _elapsed_vec;
}

void	PmergeMe::setElapsedVector(double elapsed) {
	_measuredVector = true;
	_elapsed_vec = elapsed;
}

double	PmergeMe::getElapsedDeque(void) {
	if (!_measuredDeque) {
		throw std::runtime_error("not measured");
	}
	return _elapsed_deq;
}

void	PmergeMe::setElapsedDeque(double elapsed) {
	_measuredDeque = true;
	_elapsed_deq = elapsed;
}

std::string::size_type	PmergeMe::getSizeVector(void) {

	if (_ans_vec.size() == 0) {
		throw std::logic_error("Not enough numbers");
	}
	return _ans_vec.size();
}

std::string::size_type	PmergeMe::getSizeDeque(void) {

	if (_ans_deq.size() == 0) {
		throw std::logic_error("Not enough numbers");
	}
	return _ans_deq.size();
}

void	PmergeMe::printTimeVector(void) {
	std::cout << "Time to process a range of " << std::setw(4) << std::setfill(' ') << getSizeVector() << " elements with std::vector : " << getElapsedVector() << " msec" << std::endl;
}

void	PmergeMe::printTimeDeque(void) {
	std::cout << "Time to process a range of " << std::setw(4) << std::setfill(' ') << getSizeDeque() << " elements with std::deque  : " << getElapsedDeque() << " msec" << std::endl;
}

std::vector<std::vector<int> >	PmergeMe::mergeInsertVector(std::vector<std::vector<int> >& origin) {
	if (origin.size() == 1) {
		return origin;
	}
	std::vector<std::vector<int> > arg;
	for (size_t n = 0; n + 1 < origin.size(); n += 2) {
		std::vector<int> tmp;
		if (origin[n].back() < origin[n + 1].back()) {
			tmp.insert(tmp.end(), origin[n].begin(), origin[n].end());
			tmp.insert(tmp.end(), origin[n + 1].begin(), origin[n + 1].end());
		} else {
			tmp.insert(tmp.end(), origin[n + 1].begin(), origin[n + 1].end());
			tmp.insert(tmp.end(), origin[n].begin(), origin[n].end());
		}
		arg.push_back(tmp);
	}
	std::vector<int> tmp = origin.back();
	std::vector<std::vector<int> > sorted = mergeInsertVector(arg);

	std::vector<std::vector<int> > ans;
	int flag = 1;
	int start = 0;
	int j = 1;
	size_t end = 1;
	while (flag) {
		if (end >= sorted.size()) {
			end = sorted.size();
			flag = false;
		}
		for (size_t p = start; p < end; p++) {
			std::vector<int> big(sorted[p].begin() + sorted[p].size() / 2, sorted[p].end());
			ans.push_back(big);
		}
		int sub = 0;
		if (flag == false && origin.size() % 2) {
			ans.insert(lowerBound(ans.begin(), ans.end(), tmp.back()), tmp);
			sub = 1;
		}
		std::vector<int> it_ve;
		for (int p = end; p > start; p--) {
			size_t it_end = start + p + sub - 1;
			for (std::vector<int>::iterator it = it_ve.begin(); it != it_ve.end(); it++) {
				if (sorted[p - 1][sorted[p - 1].size() - 1] >= *it)
					it_end++;
			}
			std::vector<int> small(sorted[p - 1].begin(), sorted[p - 1].begin() + sorted[p - 1].size() / 2);
			it_ve.push_back(sorted[p - 1][sorted[p - 1].size() / 2 - 1]);
			std::vector<std::vector<int> >::iterator pos = lowerBound(ans.begin(), ans.begin() + it_end, sorted[p - 1][sorted[p - 1].size() / 2 - 1]);
			ans.insert(pos, small);
		}
		start = end;
		end = start + jacobsthal(j);
		j++;
	}
	return (ans);
}

std::deque<std::deque<int> >	PmergeMe::mergeInsertDeque(std::deque<std::deque<int> >& origin) {
	if (origin.size() == 1) {
		return origin;
	}
	std::deque<std::deque<int> > arg;
	for (size_t n = 0; n + 1 < origin.size(); n += 2) {
		std::deque<int> tmp;
		if (origin[n].back() < origin[n + 1].back()) {
			tmp.insert(tmp.end(), origin[n].begin(), origin[n].end());
			tmp.insert(tmp.end(), origin[n + 1].begin(), origin[n + 1].end());
		} else {
			tmp.insert(tmp.end(), origin[n + 1].begin(), origin[n + 1].end());
			tmp.insert(tmp.end(), origin[n].begin(), origin[n].end());
		}
		arg.push_back(tmp);
	}
	std::deque<int> tmp = origin.back();
	std::deque<std::deque<int> > sorted = mergeInsertDeque(arg);

	std::deque<std::deque<int> > ans;
	int flag = 1;
	int start = 0;
	int j = 1;
	size_t end = 1;
	while (flag) {
		if (end >= sorted.size()) {
			end = sorted.size();
			flag = false;
		}
		for (size_t p = start; p < end; p++) {
			std::deque<int> big(sorted[p].begin() + sorted[p].size() / 2, sorted[p].end());
			ans.push_back(big);
		}
		int sub = 0;
		if (flag == false && origin.size() % 2) {
			ans.insert(lowerBound(ans.begin(), ans.end(), tmp.back()), tmp);
			sub = 1;
		}
		std::deque<int> it_ve;
		for (int p = end; p > start; p--) {
			size_t it_end = start + p + sub - 1;
			for (std::deque<int>::iterator it = it_ve.begin(); it != it_ve.end(); it++) {
				if (sorted[p - 1][sorted[p - 1].size() - 1] >= *it)
					it_end++;
			}
			std::deque<int> small(sorted[p - 1].begin(), sorted[p - 1].begin() + sorted[p - 1].size() / 2);
			it_ve.push_back(sorted[p - 1][sorted[p - 1].size() / 2 - 1]);
			std::deque<std::deque<int> >::iterator pos = lowerBound(ans.begin(), ans.begin() + it_end, sorted[p - 1][sorted[p - 1].size() / 2 - 1]);
			ans.insert(pos, small);
		}
		start = end;
		end = start + jacobsthal(j);
		j++;
	}
	return (ans);
}

void	PmergeMe::sortVector(void) {
	clock_t	start = clock();
	_ans_vec = mergeInsertVector(_vec);
	clock_t	end = clock();
	setElapsedVector(double(end - start) / CLOCKS_PER_SEC * 1000);
}

void	PmergeMe::sortDeque(void) {
	clock_t	start = clock();
	_ans_deq = mergeInsertDeque(_deq);
	clock_t	end = clock();
	setElapsedDeque(double(end - start) / CLOCKS_PER_SEC * 1000);
}

int	PmergeMe::jacobsthal(int n) {
	int	a = 0;
	int	b = 2;
	if (n <= 0)
		return a;
	for (int i = 1; i < n; i++) {
		int	next = b + 2 * a;
		a = b;
		b = next;
	}
	return b;
}

void	PmergeMe::parseVector(int argc, char *argv[]) {
	long	tmp;
	char	*endptr;

	for (int n = 1; n < argc; n++) {
		if (!isdigit(static_cast<unsigned char>(*(*(argv + n))))) {
			throw std::runtime_error("invalid input");
		}
		tmp = strtol(*(argv + n), &endptr, 10);
		if (*endptr != '\0' || tmp < 0 || tmp > std::numeric_limits<int>::max()) {
			throw std::runtime_error("invalid input");
		}
		pushVector(std::vector<int>(1, tmp));
	}
}

void	PmergeMe::parseDeque(int argc, char *argv[]) {
	long	tmp;
	char	*endptr;

	for (int n = 1; n < argc; n++) {
		if (!isdigit(static_cast<unsigned char>(*(*(argv + n))))) {
			throw std::runtime_error("invalid input");
		}
		tmp = strtol(*(argv + n), &endptr, 10);
		if (*endptr != '\0' || tmp < 0 || tmp > std::numeric_limits<int>::max()) {
			throw std::runtime_error("invalid input");
		}
		pushDeque(std::deque<int>(1, tmp));
	}
}

void	PmergeMe::printVector(std::string msg) {
	std::cout << msg;
	if (msg == "After:") {
		if (!_measuredVector) {
			throw std::runtime_error("not measured");
		}
		for (std::vector<std::vector<int> >::iterator i = _ans_vec.begin(); i != _ans_vec.end(); ++i) {
			std::cout << " " << (*i)[0];
		}
	} else {
		for (std::vector<std::vector<int> >::iterator i = _vec.begin(); i != _vec.end(); ++i) {
			std::cout << " " << (*i)[0];
		}
	}
	std::cout << std::endl;
}

void	PmergeMe::printDeque(std::string msg) {
	std::cout << msg;
	if (msg == "After:") {
		if (!_measuredDeque) {
			throw std::runtime_error("not measured");
		}
		for (std::deque<std::deque<int> >::iterator i = _ans_deq.begin(); i != _ans_deq.end(); ++i) {
			std::cout << " " << (*i)[0];
		}
	} else {
		for (std::deque<std::deque<int> >::iterator i = _deq.begin(); i != _deq.end(); ++i) {
			std::cout << " " << (*i)[0];
		}
	}
	std::cout << std::endl;
}

void	PmergeMe::sortAll(int argc, char *argv[]) {
	parseVector(argc, argv);
	parseDeque(argc, argv);
	printVector("Before:");
	#if DEBUG
		printDeque("Before:");
	#endif
	sortVector();
	sortDeque();
	#if DEBUG
		printVector("After:");
	#endif
	printDeque("After:");

	printTimeVector();
	printTimeDeque();
}
