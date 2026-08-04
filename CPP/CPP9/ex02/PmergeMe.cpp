#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		_vectorData = other._vectorData;
		_dequeData = other._dequeData;
	}
	return *this;
}

void PmergeMe::addNumber(int num) {
	_vectorData.push_back(num);
	_dequeData.push_back(num);
}

const std::vector<int>& PmergeMe::getVector() const {
	return _vectorData;
}

const std::deque<int>& PmergeMe::getDeque() const {
	return _dequeData;
}

static size_t jacobsthal(size_t n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	size_t a = 0, b = 1;
	for (size_t i = 2; i <= n; i++) {
		size_t temp = b + 2 * a;
		a = b;
		b = temp;
	}
	return b;
}

void PmergeMe::fordJohnsonVector(std::vector<int>& arr) {
	if (arr.size() <= 1)
		return;

	bool hasStraggler = (arr.size() % 2 != 0);
	int straggler = 0;
	if (hasStraggler) {
		straggler = arr.back();
		arr.pop_back();
	}

	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < arr.size(); i += 2) {
		if (arr[i] >= arr[i + 1])
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
		else
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
	}

	std::vector<int> largerElements;
	for (size_t i = 0; i < pairs.size(); i++)
		largerElements.push_back(pairs[i].first);

	fordJohnsonVector(largerElements);

	std::vector<std::pair<int, int> > sortedPairs;
	std::vector<bool> used(pairs.size(), false);
	for (size_t i = 0; i < largerElements.size(); i++) {
		for (size_t j = 0; j < pairs.size(); j++) {
			if (!used[j] && pairs[j].first == largerElements[i]) {
				sortedPairs.push_back(pairs[j]);
				used[j] = true;
				break;
			}
		}
	}

	std::vector<int> mainChain;
	std::vector<int> pendChain;
	for (size_t i = 0; i < sortedPairs.size(); i++) {
		mainChain.push_back(sortedPairs[i].first);
		pendChain.push_back(sortedPairs[i].second);
	}

	if (!pendChain.empty())
		mainChain.insert(mainChain.begin(), pendChain[0]);

	size_t lastJacobsthal = 1;
	size_t k = 3;

	while (true) {
		size_t currJacobsthal = jacobsthal(k);
		if (currJacobsthal > pendChain.size())
			currJacobsthal = pendChain.size();

		for (size_t i = currJacobsthal; i > lastJacobsthal; i--) {
			int valToInsert = pendChain[i - 1];
			int targetA = sortedPairs[i - 1].first;

			std::vector<int>::iterator upperBound = std::find(mainChain.begin(), mainChain.end(), targetA);
			std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), upperBound, valToInsert);
			mainChain.insert(pos, valToInsert);
		}

		if (currJacobsthal == pendChain.size())
			break;

		lastJacobsthal = currJacobsthal;
		k++;
	}

	if (hasStraggler) {
		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(pos, straggler);
	}

	arr = mainChain;
}

void PmergeMe::fordJohnsonDeque(std::deque<int>& arr) {
	if (arr.size() <= 1)
		return;

	bool hasStraggler = (arr.size() % 2 != 0);
	int straggler = 0;
	if (hasStraggler) {
		straggler = arr.back();
		arr.pop_back();
	}

	std::deque<std::pair<int, int> > pairs;
	for (size_t i = 0; i < arr.size(); i += 2) {
		if (arr[i] >= arr[i + 1])
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
		else
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
	}

	std::deque<int> largerElements;
	for (size_t i = 0; i < pairs.size(); i++)
		largerElements.push_back(pairs[i].first);

	fordJohnsonDeque(largerElements);

	std::deque<std::pair<int, int> > sortedPairs;
	std::vector<bool> used(pairs.size(), false);
	for (size_t i = 0; i < largerElements.size(); i++) {
		for (size_t j = 0; j < pairs.size(); j++) {
			if (!used[j] && pairs[j].first == largerElements[i]) {
				sortedPairs.push_back(pairs[j]);
				used[j] = true;
				break;
			}
		}
	}

	std::deque<int> mainChain;
	std::deque<int> pendChain;
	for (size_t i = 0; i < sortedPairs.size(); i++) {
		mainChain.push_back(sortedPairs[i].first);
		pendChain.push_back(sortedPairs[i].second);
	}

	if (!pendChain.empty())
		mainChain.push_front(pendChain[0]);

	size_t lastJacobsthal = 1;
	size_t k = 3;

	while (true) {
		size_t currJacobsthal = jacobsthal(k);
		if (currJacobsthal > pendChain.size())
			currJacobsthal = pendChain.size();

		for (size_t i = currJacobsthal; i > lastJacobsthal; i--) {
			int valToInsert = pendChain[i - 1];
			int targetA = sortedPairs[i - 1].first;

			std::deque<int>::iterator upperBound = std::find(mainChain.begin(), mainChain.end(), targetA);
			std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), upperBound, valToInsert);
			mainChain.insert(pos, valToInsert);
		}

		if (currJacobsthal == pendChain.size())
			break;

		lastJacobsthal = currJacobsthal;
		k++;
	}

	if (hasStraggler) {
		std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(pos, straggler);
	}

	arr = mainChain;
}

void PmergeMe::sortVector() {
	fordJohnsonVector(_vectorData);
}

void PmergeMe::sortDeque() {
	fordJohnsonDeque(_dequeData);
}
