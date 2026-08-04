#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <sys/time.h>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <string>
#include <deque>
#include <sstream>

class PmergeMe {
private:
	std::vector<int> _vectorData;
	std::deque<int> _dequeData;

	void fordJohnsonVector(std::vector<int>& arr);
	void fordJohnsonDeque(std::deque<int>& arr);

public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	void addNumber(int num);
	void sortVector();
	void sortDeque();
	
	const std::vector<int>& getVector() const;
	const std::deque<int>& getDeque() const;
};

#endif
